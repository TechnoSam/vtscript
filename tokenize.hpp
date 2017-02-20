// File: tokenize.hpp
// Author: Samuel McFalls

#ifndef TOKENIZE_H
#define TOKENIZE_H

#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <ctype.h>
#include <stdexcept>

#include "expression.hpp"

class Tokenizer {

public:

	// Default constructor
	Tokenizer();

	// Tokenizes an input stream
	// @param code The input stream representing a vtscript program
	// @return A vector of tokens
	// @throw runtime_error If parenthesis are mismatched
	std::vector<std::string> tokenize(std::istream & code);

	// Builds an AST
	// @param tokens A vector of tokens - ideally produced by tokenize
	// @return An Expression that is the root of the AST
	// @throw runtime_error If bad syntax or parenthesis are mismatched
	Expression buildAST(std::vector<std::string>& tokens);

private:
	
	void recursiveBuildAST(Expression& node, std::vector<std::string>& tokens, std::vector<std::string>::iterator& it);

	Atom selectAtom(std::string value);

	Atom::Type whatType(std::string value);

	std::vector<char> delims;

	bool isDelim(char check);

	bool isValidToken(std::string token);

	bool isOnlyDouble(const char* str);

};

#endif