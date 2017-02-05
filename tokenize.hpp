// File: tokenize.hpp

#include <vector>
#include <string>
#include <fstream>
#include <sstream>

#include "ASTNode.hpp"

class Tokenizer {

public:

	Tokenizer();

	std::vector<std::string> tokenize(std::istream & code);

	ASTNode buildAST(std::vector<std::string> tokens);

private:

	std::vector<char> delims;

	bool isDelim(char check);

};