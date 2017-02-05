// File: tokenize.hpp

#include <vector>
#include <string>
#include <fstream>
#include <sstream>

class Tokenizer {

public:

	Tokenizer();

	std::vector<std::string> tokenize(std::istream & code);

private:

	std::vector<char> delims;

	bool isDelim(char check);

};