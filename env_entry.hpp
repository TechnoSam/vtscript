// File: EnvEntry.hpp
// Author: Samuel McFalls

#ifndef ENVENTRY_H
#define ENVENTRY_H

#include <vector>

#include "atom.hpp"

class EnvEntry {

public:

	// Typdef for the possible types of Environment Entry
	typedef enum e_Env {NONE, BOOL, NUMBER, FPTR_BOOL, FPTR_NUMBER} Type;

	// Typedef for a function pointer that takes a vector of Atoms as input and 
	// produces a bool output
	typedef bool(*fptrBool)(std::vector<Atom>);

	// Typedef for a function pointer that takes a vector of Atoms as input and 
	// produces a double output
	typedef double(*fptrNumber)(std::vector<Atom>);

	// Default constructor
	// Type NONE with no value
	EnvEntry();

	// Contructs an entry with a bool
	// Set the type to BOOL
	// @param value The value store
	EnvEntry(bool value);

	// Contructs an entry with a double
	// Set the type to NUMBER
	// @param value The value store
	EnvEntry(double value);

	// Contructs an entry with a fptrBool
	// Set the type to FPTR_BOOL
	// @param func The function store
	EnvEntry(fptrBool func);

	// Contructs an entry with a fptrNumber
	// Set the type to FPTR_NUMBER
	// @param func The function store
	EnvEntry(fptrNumber func);

	// Gets the type of an EnvEntry
	// @return The type of the EnvEntry
	Type getType();

	// Gets the BOOL value of an EnvEntry
	// @return The BOOL value of the EnvEntry
	// @throws logic_error if EnvEntry is not of type BOOL
	bool getBool();

	// Gets the NUMBER value of an EnvEntry
	// @return The NUMBER value of the EnvEntry
	// @throws logic_error if EnvEntry is not of type NUMBER
	double getNumber();

	// Gets the FPTR_BOOL value of an EnvEntry
	// @return The FPTR_BOOL value of the EnvEntry
	// @throws logic_error if EnvEntry is not of type FPTR_BOOL
	fptrBool getFptrBool();

	// Gets the FPTR_NUMBER value of an EnvEntry
	// @return The FPTR_NUMBER value of the EnvEntry
	// @throws logic_error if EnvEntry is not of type FPTR_NUMBER
	fptrNumber getFptrNumber();

private:

	Type type;

	bool boolVal;

	double numberVal;

	fptrBool boolFunc;

	fptrNumber numberFunc;

};

#endif