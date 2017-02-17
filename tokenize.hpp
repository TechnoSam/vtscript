// File: tokenize.hpp
// Author: Samuel McFalls

#ifndef TOKENIZE_H
#define TOKENIZE_H

#include <vector>
#include <string>
#include <fstream>
#include <sstream>

#include "expression.hpp"

class Tokenizer {

public:

	Tokenizer();

	std::vector<std::string> tokenize(std::istream & code);

	Expression buildAST(std::vector<std::string>& tokens);

private:
	
	void recursiveBuildAST(Expression& node, std::vector<std::string>& tokens, std::vector<std::string>::iterator& it);

	Atom selectAtom(std::string value);

	Atom::Type whatType(std::string value);

	std::vector<char> delims;

	bool isDelim(char check);

};

#endif