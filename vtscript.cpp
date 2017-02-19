// File: vtscript.cpp
// Description: Defines the entry point for the vtscript program.

#include <iostream>
#include <sstream>
#include <fstream>
#include "interpreter.hpp"

void runLine(std::string program, Interpreter& interp);
void run(std::istream& program, Interpreter& interp);

int main(int argc, char* argv[]) {

	Interpreter interp;

	std::string usage = "Usage: vtscript [-e <string>] [<filename>]";
	if (argc > 3) {
		std::cerr << usage << std::endl;
		return EXIT_FAILURE;
	}
	// This isn't the best way to do commandline parsing, but it doesn't really matter
	else if (argc == 3) { // Short inline program
		std::string flag = argv[1];
		if (flag != "-e") {
			std::cerr << usage << std::endl;
			return EXIT_FAILURE;
		}
		runLine(argv[2], interp);
	}
	else if (argc == 2) { // Run from file
		std::ifstream ifs(argv[1]);
		if (!ifs.good()) {
			std::cerr << "Could not find or open file: " << argv[1] << std::endl;
			return EXIT_FAILURE;
		}
		run(ifs, interp);
	}
	else { // REPL
		std::cout << "vtscript> ";
		std::string line;
		while (std::getline(std::cin, line)) {
			runLine(line, interp);
			std::cout << std::endl << "vtscript> ";
		}
	}

	return EXIT_SUCCESS;

}

void run(std::istream& program, Interpreter& interp) {

	bool ok = interp.parse(program);
	if (!ok) {
		std::cerr << "Error: Failed to parse invalid expression" << std::endl;
		return;
	}
	
	Expression result;
	try {
		result = interp.eval();
	}
	catch (InterpreterSemanticError e) {
		interp = Interpreter(); // Reseting the interpreter resets the environment
		std::cerr << "Error during evaluation: " << e.what() << std::endl;
		return;
	}

	if (result.getAtom().getType() == Atom::Type::BOOL) {
		std::string boolString = result.getAtom().getBool() ? "True" : "False";
		std::cout << "(" << boolString << ")" << std::endl;
	}
	else { // Number. Nothing else should be able to happen so other cases are untestable
		std::cout << "(" << result.getAtom().getNumber() << ")" << std::endl;
	}

}

void runLine(std::string program, Interpreter& interp) {

	std::istringstream iss(program);
	run(iss, interp);

}