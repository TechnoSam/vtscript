// File: EnvEntry.cpp
// Author: Samuel McFalls

#include "env_entry.hpp"

EnvEntry::EnvEntry() {

	type = NONE;

	boolVal = false;
	numberVal = 0.0;
	boolFunc = nullptr;
	numberFunc = nullptr;

}

EnvEntry::EnvEntry(bool value) {

	type = BOOL;

	boolVal = value;
	numberVal = 0.0;
	boolFunc = nullptr;
	numberFunc = nullptr;

}

EnvEntry::EnvEntry(double value) {

	type = NUMBER;

	boolVal = false;
	numberVal = value;
	boolFunc = nullptr;
	numberFunc = nullptr;

}

EnvEntry::EnvEntry(fptrBool func) {

	type = FPTR_BOOL;

	boolVal = false;
	numberVal = 0.0;
	boolFunc = func;
	numberFunc = nullptr;

}

EnvEntry::EnvEntry(fptrNumber func) {

	type = FPTR_NUMBER;

	boolVal = false;
	numberVal = 0.0;
	boolFunc = nullptr;
	numberFunc = func;

}

EnvEntry::Type EnvEntry::getType() {

	return type;

}

bool EnvEntry::getBool() {

	if (type != BOOL) {
		throw std::logic_error("Environment Entry is not of type Bool");
	}

	return boolVal;

}

double EnvEntry::getNumber() {

	if (type != NUMBER) {
		throw std::logic_error("Environment Entry is not of type Number");
	}

	return numberVal;

}

EnvEntry::fptrBool EnvEntry::getFptrBool() {

	if (type != FPTR_BOOL) {
		throw std::logic_error("Environment Entry is not of type Bool Function Pointer");
	}

	return boolFunc;

}

EnvEntry::fptrNumber EnvEntry::getFptrNumber() {

	if (type != FPTR_NUMBER) {
		throw std::logic_error("Environment Entry is not of type Number Function Pointer");
	}

	return numberFunc;

}