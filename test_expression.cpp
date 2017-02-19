#include "catch.hpp"
#include "expression.hpp"

TEST_CASE("Test the Expression constructors", "[expression]") {

	Expression expNone = Expression();
	Expression expBool = Expression(true);
	Expression expNumber = Expression(2.5);
	Expression expSymbol = Expression(std::string("Test"));
	Expression expAtomBool = Expression(Atom(true));

	REQUIRE(expNone.getAtom() == Atom());
	REQUIRE(expNone.getChildren().empty());
	REQUIRE(expBool.getAtom() == Atom(true));
	REQUIRE(expBool.getChildren().empty());
	REQUIRE(expNumber.getAtom() == Atom(2.5));
	REQUIRE(expNumber.getChildren().empty());
	REQUIRE(expSymbol.getAtom() == Atom(std::string("Test")));
	REQUIRE(expSymbol.getChildren().empty());
	REQUIRE(expAtomBool.getAtom() == Atom(true));
	REQUIRE(expAtomBool.getChildren().empty());

}

TEST_CASE("Tests adding children to Expressions", "[expression]") {

	Expression root = Expression(std::string("Root"));

	root.appendChild(Atom(std::string("Child 1")));
	REQUIRE(root.getChildren().size() == 1);
	REQUIRE(root.lastChild().getAtom() == Atom(std::string("Child 1")));

	root.appendChild(Expression(std::string("Child 2")));
	REQUIRE(root.getChildren().size() == 2);
	REQUIRE(root.lastChild().getAtom() == Atom(std::string("Child 2")));

}

TEST_CASE("Tests equality operator for Expressions", "[expression]") {

	Expression a = Expression(std::string("Val"));
	Expression b = Expression(std::string("Val"));
	Expression c = Expression(std::string("NotVal"));
	Expression d = Expression(5.9);

	REQUIRE(a == b);
	REQUIRE(!(a == c));
	REQUIRE(!(a == d));
	REQUIRE(!(c == d));

	a.appendChild(Atom(std::string("Child")));

	REQUIRE(!(a == b));

	b.appendChild(Atom(true));

	REQUIRE(a == b);

}