// File: tokenize.hpp

#include <vector>
#include <string>
#include <fstream>
#include <sstream>

class Tokenizer {

public:

	std::vector<std::string> parse(std::istream & code);

};