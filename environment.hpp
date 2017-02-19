// File: environment.hpp
// Author: Samuel McFalls

#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H

#include <unordered_map>
#include <string>
#include <math.h>

#include "proc.hpp"
#include "interpreter_semantic_error.hpp"
#include "EnvEntry.hpp"

class Environment {

public:

	// Default constructor
	// Pre-loads the environment with the required symbols and procedures
	Environment();

	// Defines a symbol in the environment
	// @param symbol The key associated with the value to store
	// @param entry The value to store
	// @throw InterpreterSemanticError if the symbol is already defined
	void define(std::string symbol, EnvEntry entry);

	// Gets the value associated with a symbol
	// @param symbol The key associated with the desired value
	// @throw InterpreterSemanticError if the symbol is not found
	EnvEntry fetch(std::string symbol);

private:

	std::unordered_map<std::string, EnvEntry> env;

};

#endif