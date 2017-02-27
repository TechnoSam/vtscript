// File: proc.cpp
// Author: Samuel McFalls

#include "proc.hpp"

bool notProc(std::vector<Atom> args) {

	if (args.empty()) {
		throw InterpreterSemanticError("No arguments to unary NOT procedure");
	}
	if (args.size() > 1) {
		throw InterpreterSemanticError("Too many args to unary NOT procedure");
	}
	if (args.at(0).getType() != Atom::Type::BOOL) {
		throw InterpreterSemanticError("Improper type for BOOL NOT procedure");
	}

	return !args.at(0).getBool();

}

bool andProc(std::vector<Atom> args) {

	if (args.empty()) {
		throw InterpreterSemanticError("No arguments to m-ary AND procedure");
	}

	bool andR = true;
	for (auto it = args.begin(); it != args.end(); ++it) {
		Atom curr = *it;
		if (curr.getType() != Atom::Type::BOOL) {
			throw InterpreterSemanticError("Improper type for BOOL AND procedure");
		}
		andR = andR && curr.getBool();
	}

	return andR;

}

bool orProc(std::vector<Atom> args) {

	if (args.empty()) {
		throw InterpreterSemanticError("No arguments to m-ary OR procedure");
	}

	bool orR = false;
	for (auto it = args.begin(); it != args.end(); ++it) {
		Atom curr = *it;
		if (curr.getType() != Atom::Type::BOOL) {
			throw InterpreterSemanticError("Improper type for BOOL OR procedure");
		}
		orR = orR || curr.getBool();
	}

	return orR;

}

bool ltProc(std::vector<Atom> args) {

	if (args.empty()) {
		throw InterpreterSemanticError("No arguments to binary LESS THAN procedure");
	}
	if (args.size() < 2) {
		throw InterpreterSemanticError("Too few arguments to binary LESS THAN procedure");
	}
	if (args.size() > 2) {
		throw InterpreterSemanticError("Too many arguments to binary LESS THAN procedure");
	}
	if (args.at(0).getType() != Atom::Type::NUMBER || args.at(1).getType() != Atom::Type::NUMBER) {
		throw InterpreterSemanticError("Improper type for NUMBER LESS THAN procedure");
	}

	return args.at(0).getNumber() < args.at(1).getNumber();

}

bool lteProc(std::vector<Atom> args) {

	if (args.empty()) {
		throw InterpreterSemanticError("No arguments to binary LESS THAN EQUAL procedure");
	}
	if (args.size() < 2) {
		throw InterpreterSemanticError("Too few arguments to binary LESS THAN EQUAL procedure");
	}
	if (args.size() > 2) {
		throw InterpreterSemanticError("Too many arguments to binary LESS THAN EQUAL procedure");
	}
	if (args.at(0).getType() != Atom::Type::NUMBER || args.at(1).getType() != Atom::Type::NUMBER) {
		throw InterpreterSemanticError("Improper type for NUMBER LESS THAN EQUAL procedure");
	}

	return args.at(0).getNumber() <= args.at(1).getNumber();

}

bool gtProc(std::vector<Atom> args) {

	if (args.empty()) {
		throw InterpreterSemanticError("No arguments to binary GREATER THAN procedure");
	}
	if (args.size() < 2) {
		throw InterpreterSemanticError("Too few arguments to binary GREATER THAN procedure");
	}
	if (args.size() > 2) {
		throw InterpreterSemanticError("Too many arguments to binary GREATER THAN procedure");
	}
	if (args.at(0).getType() != Atom::Type::NUMBER || args.at(1).getType() != Atom::Type::NUMBER) {
		throw InterpreterSemanticError("Improper type for NUMBER GREATER THAN procedure");
	}

	return args.at(0).getNumber() > args.at(1).getNumber();

}

bool gteProc(std::vector<Atom> args) {

	if (args.empty()) {
		throw InterpreterSemanticError("No arguments to binary GREATER THAN EQUAL procedure");
	}
	if (args.size() < 2) {
		throw InterpreterSemanticError("Too few arguments to binary GREATER THAN EQUAL procedure");
	}
	if (args.size() > 2) {
		throw InterpreterSemanticError("Too many arguments to binary GREATER THAN EQUAL procedure");
	}
	if (args.at(0).getType() != Atom::Type::NUMBER || args.at(1).getType() != Atom::Type::NUMBER) {
		throw InterpreterSemanticError("Improper type for NUMBER GREATER THAN EQUAL procedure");
	}

	return args.at(0).getNumber() >= args.at(1).getNumber();

}

bool equalProc(std::vector<Atom> args) {

	if (args.empty()) {
		throw InterpreterSemanticError("No arguments to binary EQUAL procedure");
	}
	if (args.size() < 2) {
		throw InterpreterSemanticError("Too few arguments to binary EQUAL procedure");
	}
	if (args.size() > 2) {
		throw InterpreterSemanticError("Too many arguments to binary EQUAL procedure");
	}
	if (args.at(0).getType() != Atom::Type::NUMBER || args.at(1).getType() != Atom::Type::NUMBER) {
		throw InterpreterSemanticError("Improper type for NUMBER EQUAL procedure");
	}

	return args.at(0).getNumber() == args.at(1).getNumber();

}

double sumProc(std::vector<Atom> args) {

	if (args.empty()) {
		throw InterpreterSemanticError("No arguments to m-ary SUM procedure");
	}

	double sum = 0;
	for (auto it = args.begin(); it != args.end(); ++it) {
		Atom curr = *it;
		if (curr.getType() != Atom::Type::NUMBER) {
			throw InterpreterSemanticError("Improper type for NUMBER SUM procedure");
		}
		sum += curr.getNumber();
	}

	return sum;

}

double subProc(std::vector<Atom> args) {

	if (args.empty()) {
		throw InterpreterSemanticError("No arguments to unary or binary SUB/NEG procedure");
	}
	if (args.size() > 2) {
		throw InterpreterSemanticError("Too many arguments to unary or binary SUB/NEG procedure");
	}

	double sub = 0;
	if (args.size() == 1) {
		if (args.at(0).getType() != Atom::Type::NUMBER) {
			throw InterpreterSemanticError("Improper type for NUMBER NEG procedure");
		}
		sub = -args.at(0).getNumber();
	}
	else {
		if (args.at(0).getType() != Atom::Type::NUMBER || args.at(1).getType() != Atom::Type::NUMBER) {
			throw InterpreterSemanticError("Improper type for NUMBER SUB procedure");
		}
		sub = args.at(0).getNumber() - args.at(1).getNumber();
	}

	return sub;

}

double multProc(std::vector<Atom> args) {

	if (args.empty()) {
		throw InterpreterSemanticError("No arguments to m-ary MULT procedure");
	}

	double product = 1;
	for (auto it = args.begin(); it != args.end(); ++it) {
		Atom curr = *it;
		if (curr.getType() != Atom::Type::NUMBER) {
			throw InterpreterSemanticError("Improper type for NUMBER MULT procedure");
		}
		product *= curr.getNumber();
	}

	return product;

}

double divProc(std::vector<Atom> args) {

	if (args.empty()) {
		throw InterpreterSemanticError("No arguments to binary DIV procedure");
	}
	if (args.size() < 2) {
		throw InterpreterSemanticError("Too few arguments to binary DIV procedure");
	}
	if (args.size() > 2) {
		throw InterpreterSemanticError("Too many arguments to binary DIV procedure");
	}
	if (args.at(0).getType() != Atom::Type::NUMBER || args.at(1).getType() != Atom::Type::NUMBER) {
		throw InterpreterSemanticError("Improper type for NUMBER DIV procedure");
	}

	return args.at(0).getNumber() / args.at(1).getNumber();

}