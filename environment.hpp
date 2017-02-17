#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H

#include <unordered_map>
#include <string>

#include "EnvEntry.hpp"

class Environment {

public:

	bool define(std::string, EnvEntry);

	EnvEntry fetch(std::string);

private:

	std::unordered_map<std::string, EnvEntry> env;

};

#endif