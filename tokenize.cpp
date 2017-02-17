// File: tokenize.cpp
// Author: Samuel McFalls

#include "tokenize.hpp"

Tokenizer::Tokenizer() {

	delims.push_back(' ');
	delims.push_back('(');
	delims.push_back(')');

}

std::vector<std::string> Tokenizer::tokenize(std::istream & code) {

	std::vector<std::string> expr;

	char buffer;
	std::string token;

	size_t openCount = 0;
	size_t closeCount = 0;

	while (code.get(buffer)) {

		if (isDelim(buffer)) {

			// Save the token into expr if needed
			if (token != "") { // TODO check for tabs
				expr.push_back(token);
			}

			// Clear the token
			token = "";

			// Save parens as well
			if (buffer == '(' || buffer == ')') {
				expr.push_back(std::string(1, buffer));
				if (buffer == '(') { openCount++; }
				else { closeCount++; }
			}

		}
		else {
			token.push_back(buffer);
		}

	}

	if (token != "") {
		expr.push_back(token);
	}

	if (openCount != closeCount) { throw std::runtime_error("Mismatched parenthesis"); }

	return expr;

}

ASTNode* Tokenizer::buildAST(std::vector<std::string> tokens) {

	ASTNode* curr = new ASTNode("root");

	for (auto it = tokens.begin(); it != tokens.end(); ++it) {

		if (*it == "(") { // Move down
			++it;
			if (*it == "(" || *it == ")") {
				throw std::runtime_error("Bad syntax");
			}
			curr->appendChild(*it);
			curr = curr->lastChild();
		}
		else if (*it == ")") { // Move up
			if (curr->getParent() == nullptr) {
				throw std::runtime_error("Mismatched parenthesis");
			}
			curr = curr->getParent();
		}
		else {
			curr->appendChild(*it);
		}

	}

	// If curr's parent is not the root, then we have a paren error
	if (curr->getParent() != nullptr) {
		throw std::runtime_error("Mismatched parenthesis");
	}

	return curr;
}

Expression Tokenizer::buildAST2(std::vector<std::string>& tokens) {
	
	Expression node;
	if (tokens.size() < 2) {
		throw std::runtime_error("Not enough tokens");
	}
	if (tokens.front() != "(") {
		throw std::runtime_error("Bad syntax");
	}
	tokens.erase(tokens.begin());
	if (tokens.front() == "(" || tokens.front() == ")") {
		throw std::runtime_error("Bad syntax");
	}
	Atom atom = selectAtom(tokens.front());
	tokens.erase(tokens.begin());
	node = Expression(atom);

	recursiveBuildAST(node, tokens);

	if (!tokens.empty()) {
		throw std::runtime_error("Mismatched parenthesis");
	}

	return node;

}

void Tokenizer::recursiveBuildAST(Expression& node, std::vector<std::string>& tokens) {

	while (!tokens.empty()) {
		if (tokens.front() == "(") {
			tokens.erase(tokens.begin());
			if (tokens.size() < 2) {
				throw std::runtime_error("Bad syntax");
			}
			if (tokens.front() == "(" || tokens.front() == ")") {
				throw std::runtime_error("Bad syntax");
			}
			Atom atom = selectAtom(tokens.front());
			tokens.erase(tokens.begin());
			Expression exp = Expression(atom);
			recursiveBuildAST(exp, tokens);
			node.appendChild(exp);
		}
		else if (tokens.front() == ")") {
			tokens.erase(tokens.begin());
			return;
		}
		else {
			Atom atom = selectAtom(tokens.front());
			tokens.erase(tokens.begin());
			node.appendChild(atom);
			recursiveBuildAST(node, tokens);
			return;
		}
	}

	/*while (tokens.front() != "(" && tokens.front() != ")") {
		Atom atom = selectAtom(tokens.front());
		tokens.erase(tokens.begin());
		node.appendChild(atom);
	}
	if (tokens.front() == "(") {
		tokens.erase(tokens.begin());
		if (tokens.size() < 2) {
			throw std::runtime_error("Bad syntax");
		}
		if (tokens.front() == "(" || tokens.front() == ")") {
			throw std::runtime_error("Bad syntax");
		}
		Atom atom = selectAtom(tokens.front());
		node.appendChild(atom);
		recursiveBuildAST(node.lastChild(), tokens);
	}
	else {
		tokens.erase(tokens.begin());
		return;
	}*/


}

bool Tokenizer::isDelim(char check) {

	bool ret = false;

	for (auto it = delims.begin(); it != delims.end(); ++it) {
		if (check == *it) {
			ret = true;
		}
	}

	return ret;

}

Atom Tokenizer::selectAtom(std::string value) {

	Atom atom;

	Atom::Type type = whatType(value);
	switch (type) {
	case Atom::Type::NUMBER:
		atom = Atom(std::stod(value));
		break;
	case Atom::Type::BOOL:
		atom = (value == "True") ? Atom(true) : Atom(false);
		break;
	case Atom::Type::SYMBOL:
		atom = Atom(value);
		break;
	default:
		atom = Atom();
	}

	return atom;

}

Atom::Type Tokenizer::whatType(std::string value) {

	Atom::Type ret = Atom::Type::NONE;

	try {
		std::stod(value);
		ret = Atom::Type::NUMBER;
	}
	catch(...) {
		if (value == "True" || value == "False") {
			ret = Atom::Type::BOOL;
		}
		else {
			ret = Atom::Type::SYMBOL;
		}
	}

	return ret;

}