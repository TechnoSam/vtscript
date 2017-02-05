// File: tokenize.cpp

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

	return expr;

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