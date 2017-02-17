// File: EnvEntry.hpp
// Author: Samuel McFalls

#ifndef ENVENTRY_H
#define ENVENTRY_H

#include <vector>

#include "Atom.hpp"

class EnvEntry {

public:

	typedef enum e_Env {BOOL, NUMBER, FPTR_BOOL, FPTR_NUMBER} Type;

	typedef bool(*fptrBool)(std::vector<Atom>);

	typedef double(*fptrNumber)(std::vector<Atom>);

	EnvEntry(bool value);

	EnvEntry(double value);

	EnvEntry(fptrBool func);

	EnvEntry(fptrNumber func);

	Type getType();

	bool getBool();

	double getNumber();

	fptrBool getFptrBool();

	fptrNumber getFptrNumber();

private:

	Type type;
	bool boolVal;
	double numberVal;
	fptrBool boolFunc;
	fptrNumber numberFunc;

};

#endif