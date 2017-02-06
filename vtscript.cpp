// File: vtscript.cpp
// Description: Defines the entry point for the vtscript program.

#include <iostream>
#include "environment.hpp"
#include "expression.hpp"
#include "interpreter.hpp"
#include "tokenize.hpp"
#include "ASTNode.hpp"

int main(int argc, char* argv[]) {

	Tokenizer tkn;
	std::string testS = "(begin(define a 1)(define b pi)(if (< a b) b a))";
	std::stringstream ssTest(testS);
	std::vector<std::string> test = tkn.tokenize(ssTest);

	for (unsigned int i = 0; i < test.size(); i++) {
		std::cout << test.at(i) << ", ";
	}

	ASTNode* testAST = tkn.buildAST(test);

	std::cout << std::endl;

}