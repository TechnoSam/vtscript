// File: environment.cpp
// Author: Samuel McFalls

#include "environment.hpp"

Environment::Environment() {

}

bool Environment::define(std::string, EnvEntry) {

	return false;

}

EnvEntry Environment::fetch(std::string) {

	return EnvEntry(false);

}