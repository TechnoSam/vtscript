// File: expression.hpp
// Author: Samuel McFalls

#ifndef EXPRESSION_H
#define EXPRESSION_H

#include <vector>
#include <string>

#include "Atom.hpp"

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

	// Equality operator for two Expressions, two expressions are equal if the have the same 
	// type, atom value, and number of arguments
	bool operator==(const Expression & exp) const noexcept;

	// Gets the parent of an Expression
	// @return The parent of the Expression
	Expression* getParent() const;

	// Gets the last child of an Expression
	// @return The last child of the Expression if it has children, nullptr otherwise
	Expression* lastChild() const;

	// Gets all children of an Expression
	// @return The vector of child pointers
	std::vector<Expression*> getChildren() const;

	// Appends a child to an Expression
	// @param atomAppend The atom to be held by the appended Expression
	void appendChild(Atom atomAppend);

	// Gets the Atom held by an Expression
	// @return The atom held by the Expression
	Atom getAtom() const;

private:

	Expression* parent;

	std::vector<Expression*> children;

	Atom atom;

};

#endif // EXPRESSION_H