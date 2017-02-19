// File: environment.cpp
// Author: Samuel McFalls

#include "environment.hpp"

Environment::Environment() {

	env[std::string("pi")] = EnvEntry(atan2(0, -1));

	EnvEntry::fptrBool notFptr = notProc;
	env[std::string("not")] = EnvEntry(notFptr);

	EnvEntry::fptrBool andFptr = andProc;
	env[std::string("and")] = EnvEntry(andFptr);

	EnvEntry::fptrBool orFptr = orProc;
	env[std::string("or")] = EnvEntry(orFptr);

	EnvEntry::fptrBool ltFptr = ltProc;
	env[std::string("<")] = EnvEntry(ltFptr);

	EnvEntry::fptrBool lteFptr = lteProc;
	env[std::string("<=")] = EnvEntry(lteFptr);

	EnvEntry::fptrBool gtFptr = gtProc;
	env[std::string(">")] = EnvEntry(gtFptr);

	EnvEntry::fptrBool gteFptr = gteProc;
	env[std::string(">=")] = EnvEntry(gteFptr);

	EnvEntry::fptrBool equalFptr = equalProc;
	env[std::string("=")] = EnvEntry(equalFptr);

	EnvEntry::fptrNumber sumFptr = sumProc;
	env[std::string("+")] = EnvEntry(sumFptr);

	EnvEntry::fptrNumber subFptr = subProc;
	env[std::string("-")] = EnvEntry(subFptr);

	EnvEntry::fptrNumber multFptr = multProc;
	env[std::string("*")] = EnvEntry(multFptr);

	EnvEntry::fptrNumber divFptr = divProc;
	env[std::string("/")] = EnvEntry(divFptr);

}

void Environment::define(std::string symbol, EnvEntry entry) {

	if (env.find(symbol) == env.end()) {
		env[symbol] = entry;
	}
	else {
		throw InterpreterSemanticError("Attempt to redefine symbol");
	}

}

EnvEntry Environment::fetch(std::string symbol) {

	if (env.find(symbol) == env.end()) {
		throw InterpreterSemanticError("Unknown symbol");
	}
	
	return env[symbol];

}

bool Environment::exists(std::string symbol) {

	return env.find(symbol) != env.end();

}