// File: Atom.cpp
// Author: Samuel McFalls

#include "atom.hpp"

Atom::Atom() {

	type = Atom::Type::NONE;

}

Atom::Atom(bool value) {

	type = Atom::Type::BOOL;

	boolVal = value;

	numberVal = 0.0;

	symbolVal = "";

}

Atom::Atom(double value) {

	type = Atom::Type::NUMBER;

	boolVal = false;

	numberVal = value;

	symbolVal = "";

}

Atom::Atom(const std::string& value) {

	type = Atom::Type::SYMBOL;

	boolVal = false;

	numberVal = 0.0;

	symbolVal = value;

}

Atom::Type Atom::getType() {

	return type;

}

bool Atom::getBool() {

	if (type != Atom::Type::BOOL) {
		throw std::logic_error("Atom is not of type Bool");
	}

	return boolVal;

}

double Atom::getNumber() {

	if (type != Atom::Type::NUMBER) {
		throw std::logic_error("Atom is not of type Number");
	}

	return numberVal;

}

std::string Atom::getSymbol() {

	if (type != Atom::Type::SYMBOL) {
		throw std::logic_error("Atom is not of type Symbol");
	}

	return symbolVal;

}

bool Atom::operator==(const Atom& rhs) const noexcept {

	bool isEqual = false;

	if (this->type == rhs.type) {
		switch (this->type) {
		case Atom::Type::NONE:
			isEqual = true;
			break;
		case Atom::Type::BOOL:
			isEqual = (this->boolVal == rhs.boolVal);
			break;
		case Atom::Type::NUMBER:
			isEqual = (this->numberVal == rhs.numberVal);
			break;
		case Atom::Type::SYMBOL:
			isEqual = (this->symbolVal == rhs.symbolVal);
			break;
		}
	}

	return isEqual;

}

bool Atom::operator!=(const Atom& rhs) const noexcept {

	return !operator==(rhs);

}