// File: expression.cpp
// Author: Samuel McFalls

#include "expression.hpp"

Expression::Expression() {

	parent = nullptr;

	// Children is already empty

	atom = Atom();

}

Expression::Expression(bool value) {

	parent = nullptr;

	// Children is already empty

	atom = Atom(value);

}

Expression::Expression(double value) {

	parent = nullptr;

	// Children is already empty

	atom = Atom(value);

}

Expression::Expression(const std::string & value) {

	parent = nullptr;

	// Children is already empty

	atom = Atom(value);

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

Expression* Expression::getParent() const {

	return parent;

}

Expression* Expression::lastChild() const {

	return children.at(children.size() - 1);

}

std::vector<Expression*> Expression::getChildren() const {

	return children;

}

void Expression::appendChild(Atom atomAppend) {

	Expression* child = new Expression();
	child->atom = atom;
	child->parent = this;
	children.push_back(child);

}

Atom Expression::getAtom() const {

	return atom;

}