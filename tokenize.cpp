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

	while (code.get(buffer)) {

		if (isDelim(buffer)) {

			// Save the token into expr if needed
			if (token != "") {
				expr.push_back(token);
			}

			// Clear the token
			token = "";

			// Save parens as well
			if (buffer == '(' || buffer == ')') {
				expr.push_back(std::string(1, buffer));
			}

		}
		else {
			token.push_back(buffer);
		}

	}

	if (token != "") {
		expr.push_back(token);
	}

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

bool Tokenizer::isDelim(char check) {

	bool ret = false;

	for (auto it = delims.begin(); it != delims.end(); ++it) {
		if (check == *it) {
			ret = true;
		}
	}

	return ret;

}