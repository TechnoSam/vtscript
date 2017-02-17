// File: vtscript.cpp
// Description: Defines the entry point for the vtscript program.

#include <iostream>
#include "environment.hpp"
#include "expression.hpp"
#include "interpreter.hpp"
#include "tokenize.hpp"

int main(int argc, char* argv[]) {

	Tokenizer tkn;
	// Good test
	// (if (< a b) b )a
	std::string testS = "(begin\t(define a 1)\t(define b pi)\t(if (< a b) b a))";
	std::stringstream ssTest(testS);

	std::vector<std::string> test;
	try {
		test = tkn.tokenize(ssTest);
	}
	catch (std::runtime_error &exception) {
		std::cerr << std::endl << exception.what() << std::endl;
		return EXIT_FAILURE;
	}

	for (unsigned int i = 0; i < test.size(); i++) {
		std::cout << test.at(i) << ", ";
	}

	try {
		Expression testEx = tkn.buildAST(test);
	}
	catch (std::runtime_error &exception) {
		std::cerr << std::endl << exception.what() << std::endl;
		return EXIT_FAILURE;
	}

	std::cout << std::endl;

	return EXIT_SUCCESS;

}