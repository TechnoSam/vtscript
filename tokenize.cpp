// File: tokenize.cpp
// Author: Samuel McFalls

#include "tokenize.hpp"
#include <iostream>

Tokenizer::Tokenizer() {

	delims.push_back(' ');
	delims.push_back('(');
	delims.push_back(')');
	delims.push_back('\t');
	delims.push_back(';');

}

std::vector<std::string> Tokenizer::tokenize(std::istream & code) {

	std::vector<std::string> expr;

	char buffer;
	std::string token;

	size_t openCount = 0;
	size_t closeCount = 0;

	std::string codeLine;

	while (std::getline(code, codeLine)) {

		std::stringstream codeLineS(codeLine);

		while (codeLineS.get(buffer)) {

			if (isDelim(buffer)) {

				//std::cout << buffer << std::endl;
				if (!isValidToken(token)) { throw std::runtime_error("Invalid token"); }

				// Save the token into expr if needed
				if (token != "") {
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

				// If we hit a semi-colon, read until newline or EOF
				if (buffer == ';') {
					break;
				}

			}
			else {
				token.push_back(buffer);
			}

		}
	}

	if (!isValidToken(token)) { throw std::runtime_error("Invalid token"); }
	if (token != "") {
		expr.push_back(token);
	}

	if (openCount != closeCount) { throw std::runtime_error("Mismatched parenthesis"); }

	if (expr.empty()) { throw std::runtime_error("Empty program"); }

	return expr;

}

Expression Tokenizer::buildAST(std::vector<std::string>& tokens) {
	
	Expression node;
	auto it = tokens.begin();

	if (*it != "(") {
		throw std::runtime_error("Bad syntax");
	}
	it++;
	if (*it == "(" || *it == ")") {
		throw std::runtime_error("Bad syntax");
	}
	Atom atom = selectAtom(*it);
	it++;
	node = Expression(atom);

	recursiveBuildAST(node, tokens, it);

	if (it != tokens.end()) {
		/*for (auto it2 = tokens.begin(); it2 != tokens.end(); it2++) {
			std::cout << "\"" << *it2 << "\", ";
		}
		std::cout << std::endl;*/
		throw std::runtime_error("Mismatched parenthesis");
	}

	return node;

}

void Tokenizer::recursiveBuildAST(Expression& node, std::vector<std::string>& tokens, std::vector<std::string>::iterator& it) {

	while (it != tokens.end()) {
		if (*it == "(") {
			it++;
			if (*it == "(" || *it == ")") {
				throw std::runtime_error("Bad syntax");
			}
			Atom atom = selectAtom(*it);
			it++;
			Expression exp = Expression(atom);
			recursiveBuildAST(exp, tokens, it);
			node.appendChild(exp);
		}
		else if (*it == ")") {
			it++;
			return;
		}
		else {
			Atom atom = selectAtom(*it);
			it++;
			node.appendChild(atom);
			recursiveBuildAST(node, tokens, it);
			return;
		}
	}

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

bool Tokenizer::isValidToken(std::string token) {

	bool valid = true;
	if (isdigit(token[0]) && token.length() > 1) {
		for (unsigned int i = 1; i < token.length(); i++) {
			if (!isdigit(token[i]) && token[i] != '.') {
				valid = false;
			}
		}
	}

	return valid;
}