// File: tokenize.cpp

#include "tokenize.hpp"

std::vector<std::string> Tokenizer::parse(std::istream & code) {

	std::vector<std::string> expr;

	std::string lineBuffer;
	std::string spaceBuffer;
	std::string oParenBuffer;
	std::string cParenBuffer;
	std::string token;

	while (std::getline(code, lineBuffer)) {
		
		std::stringstream ssLineBuffer(lineBuffer);
		while (std::getline(ssLineBuffer, spaceBuffer, ' ')) {

			std::stringstream ssSpaceBuffer(spaceBuffer);
			while (std::getline(ssSpaceBuffer, oParenBuffer, '(')) {

				std::stringstream ssOParentBuffer(oParenBuffer);
				while (std::getline(ssOParentBuffer, cParenBuffer, ')')) {

					expr.push_back(cParenBuffer);

				}

			}

		}

	}

	return expr;

}