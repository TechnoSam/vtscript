// File: interpreter.cpp
// Author: Samuel McFalls

#include "interpreter.hpp"

Interpreter::Interpreter() {



}

bool Interpreter::parse(std::istream & expression) noexcept {

	std::vector<std::string> tokens;
	try {
		tokens = tkn.tokenize(expression);
	}
	catch (...) {
		return false;
	}

	try {
		AST = tkn.buildAST(tokens);
	}
	catch (...) {
		return false;
	}
	
	return true;

}

Expression Interpreter::eval() {

	return postEval(AST);

}

Expression Interpreter::postEval(Expression exp) {

	// Check if we're a special form
	if (exp.getAtom().getType() == Atom::Type::SYMBOL) {
		if (exp.getAtom().getSymbol() == "begin") {
			std::vector<Expression> children = exp.getChildren();
			if (children.empty()) {
				throw InterpreterSemanticError("No children");
			}
			Expression result;
			for (auto it = children.begin(); it != children.end(); ++it) {
				Expression child = *it;
				result = postEval(child);
			}
			return result;
		}
		if (exp.getAtom().getSymbol() == "define") {
			std::vector<Expression> children = exp.getChildren();
			if (children.size() != 2) {
				throw InterpreterSemanticError("Improper number of args");
			}
			if (children.at(0).getAtom().getType() != Atom::Type::SYMBOL) {
				throw InterpreterSemanticError("First argument is not a symbol");
			}
			std::string symbol = children.at(0).getAtom().getSymbol();
			if (symbol == "begin" || symbol == "define" || symbol == "if") {
				throw InterpreterSemanticError("Attempt to redefine special form");
			}
			if (env.exists(symbol)) {
				throw InterpreterSemanticError("Attempt to redefine existing symbol");
			}
			Expression value = postEval(children.at(1));
			if (value.getAtom().getType() == Atom::Type::BOOL) {
				env.define(symbol, EnvEntry(value.getAtom().getBool()));
			}
			else {// if (value.getAtom().getType() == Atom::Type::NUMBER)
				env.define(symbol, EnvEntry(value.getAtom().getNumber()));
			}
			return value;
		}
		if (exp.getAtom().getSymbol() == "if") {
			std::vector<Expression> children = exp.getChildren();
			if (children.size() != 3) {
				throw InterpreterSemanticError("Improper number of args");
			}
			Expression condExp = postEval(children.at(0));
			if (condExp.getAtom().getType() != Atom::Type::BOOL) {
				throw InterpreterSemanticError("Condition is not a boolean");
			}
			if (condExp.getAtom().getBool()) {
				return postEval(children.at(1));
			}
			else {
				return postEval(children.at(2));
			}
		}
	}
	// If we're not a special form, evaluate all the children of the current expression
	// The children are potential arguments to procedures
	std::vector<Expression> children = exp.getChildren();
	std::vector<Atom> args;
	for (auto it = children.begin(); it != children.end(); ++it) {
		Expression child = *it;
		args.push_back(postEval(child).getAtom());
	}

	bool isProc = false;
	EnvEntry proc;
	if (exp.getAtom().getType() == Atom::Type::SYMBOL) {
		if (env.exists(exp.getAtom().getSymbol())) {
			proc = env.fetch(exp.getAtom().getSymbol());
			if (proc.getType() == EnvEntry::Type::FPTR_BOOL || proc.getType() == EnvEntry::Type::FPTR_NUMBER) {
				isProc = true;
			}
		}
	}

	if (isProc) {

		if (proc.getType() == EnvEntry::Type::FPTR_BOOL) {
			return Expression(proc.getFptrBool()(args));
		}
		return Expression(proc.getFptrNumber()(args));

	}
	else {

		if (!children.empty()) {
			throw InterpreterSemanticError("No such procedure");
		}
		if (exp.getAtom().getType() == Atom::Type::SYMBOL) {
			EnvEntry value = env.fetch(exp.getAtom().getSymbol());
			if (value.getType() == EnvEntry::Type::BOOL) {
				return Expression(value.getBool());
			}
			return Expression(value.getNumber());
		}
		return exp;

	}

}