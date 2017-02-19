// File: expression.cpp
// Author: Samuel McFalls

#include "expression.hpp"

Expression::Expression() {

	// Children is already empty

	atom = Atom();

}

Expression::Expression(bool value) {

	// Children is already empty

	atom = Atom(value);

}

Expression::Expression(double value) {

	// Children is already empty

	atom = Atom(value);

}

Expression::Expression(const std::string & value) {

	// Children is already empty

	atom = Atom(value);

}

Expression::Expression(const Atom& atomValue) {

	// Children is already empty

	atom = atomValue;

}

bool Expression::operator==(const Expression & exp) const noexcept {

	bool isEqual = false;

	// Check if the Atoms are equal
	if (this->getAtom() == exp.getAtom()) {
		// Check if the number of children is the same
		if (this->getChildren().size() == exp.getChildren().size()) {
			isEqual = true;
		}
	}

	return isEqual;

}

Expression Expression::lastChild() {

	return children.at(children.size() - 1);

}

std::vector<Expression> Expression::getChildren() const {

	return children;

}

void Expression::appendChild(Atom atomAppend) {

	Expression child = Expression(atomAppend);
	children.push_back(child);

}

void Expression::appendChild(Expression expAppend) {

	children.push_back(expAppend);

}

Atom Expression::getAtom() const {

	return atom;

}