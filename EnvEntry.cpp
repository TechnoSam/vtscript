// File: EnvEntry.cpp
// Author: Samuel McFalls

#include "EnvEntry.hpp"

EnvEntry::EnvEntry(bool value) {

}

EnvEntry::EnvEntry(double value) {

}

EnvEntry::EnvEntry(fptrBool func) {

}

EnvEntry::EnvEntry(fptrNumber func) {

}

EnvEntry::Type EnvEntry::getType() {

	return type;

}

bool EnvEntry::getBool() {

	return false;

}

double EnvEntry::getNumber() {

	return 0.0;

}

EnvEntry::fptrBool EnvEntry::getFptrBool() {

	fptrBool temp;

	return temp;

}

EnvEntry::fptrNumber EnvEntry::getFptrNumber() {

	fptrNumber temp;

	return temp;

}