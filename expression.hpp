// File: expression.hpp
// Author: Samuel McFalls

#ifndef EXPRESSION_H
#define EXPRESSION_H

#include <vector>
#include <string>

#include "atom.hpp"

class Expression {

public:

	// Default construct an Expression of type None
	Expression();

	// Construct an Expression with a single Boolean atom with value
	Expression(bool value);

	// Construct an Expression with a single Number atom with value
	Expression(double value);

	// Construct an Expression with a single Symbol atom with value
	Expression(const std::string & value);

	// Construct an Expression with an atom as given
	Expression(const Atom& atomValue);

	// Equality operator for two Expressions, two expressions are equal if the have the same 
	// type, atom value, and number of arguments
	bool operator==(const Expression & exp) const noexcept;

	// Gets the last child of an Expression
	// @return The last child of the Expression if it has children, nullptr otherwise
	Expression lastChild();

	// Gets all children of an Expression
	// @return The vector of child pointers
	std::vector<Expression> getChildren() const;

	// Appends a child to an Expression
	// @param atomAppend The atom to be held by the appended Expression
	void appendChild(Atom atomAppend);

	// Apples a child to an Expression
	// @param expAppend The Expression to append
	void appendChild(Expression expAppend);

	// Gets the Atom held by an Expression
	// @return The atom held by the Expression
	Atom getAtom() const;

private:

	std::vector<Expression> children;

	Atom atom;

};

#endif