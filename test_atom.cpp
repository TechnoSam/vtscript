#include "catch.hpp"

#include <string>

#include "atom.hpp"

TEST_CASE("Tests the Atom constructors", "[atom]") {

	Atom aNone = Atom();
	Atom aBool = Atom(true);
	Atom aNumber = Atom(2.5);
	Atom aSymbol = Atom(std::string("Test"));

	REQUIRE(aNone.getType() == Atom::Type::NONE);
	REQUIRE(aBool.getType() == Atom::Type::BOOL);
	REQUIRE(aNumber.getType() == Atom::Type::NUMBER);
	REQUIRE(aSymbol.getType() == Atom::Type::SYMBOL);

	REQUIRE(aBool.getBool());
	REQUIRE(aNumber.getNumber() == 2.5);
	REQUIRE(aSymbol.getSymbol() == "Test");

}

TEST_CASE("Tests the equality operator for Atoms", "[atom]") {

	Atom aNone1 = Atom();
	Atom aBool1 = Atom(true);
	Atom aNumber1 = Atom(2.5);
	Atom aSymbol1 = Atom(std::string("Test"));

	Atom aNone2 = Atom();
	Atom aBool2 = Atom(true);
	Atom aNumber2 = Atom(2.5);
	Atom aSymbol2 = Atom(std::string("Test"));

	Atom aNone3 = Atom();
	Atom aBool3 = Atom(false);
	Atom aNumber3 = Atom(5.3);
	Atom aSymbol3 = Atom(std::string("Not Test"));

	REQUIRE(aNone1 == aNone2);
	REQUIRE(aNone1 == aNone3);

	REQUIRE(aBool1 == aBool2);
	REQUIRE(aBool1 != aBool3);

	REQUIRE(aNumber1 == aNumber2);
	REQUIRE(aNumber1 != aNumber3);

	REQUIRE(aSymbol1 == aSymbol2);
	REQUIRE(aSymbol1 != aSymbol3);

	REQUIRE(aNone1 != aBool1);
	REQUIRE(aNone1 != aNumber1);
	REQUIRE(aNone1 != aSymbol1);

	REQUIRE(aBool1 != aNone1);
	REQUIRE(aBool1 != aNumber1);
	REQUIRE(aBool1 != aSymbol1);

	REQUIRE(aNumber1 != aNone1);
	REQUIRE(aNumber1 != aBool1);
	REQUIRE(aNumber1 != aSymbol1);

	REQUIRE(aSymbol1 != aNone1);
	REQUIRE(aSymbol1 != aBool1);
	REQUIRE(aSymbol1 != aNumber1);

}

TEST_CASE("Tests exception throwing for invalid access on Atoms", "[atom]") {

	Atom aNone = Atom();
	Atom aBool = Atom(true);
	Atom aNumber = Atom(2.5);
	Atom aSymbol = Atom(std::string("Test"));

	REQUIRE_THROWS_AS(aNone.getBool(), std::logic_error);
	REQUIRE_THROWS_AS(aNone.getNumber(), std::logic_error);
	REQUIRE_THROWS_AS(aNone.getSymbol(), std::logic_error);

	REQUIRE_THROWS_AS(aBool.getNumber(), std::logic_error);
	REQUIRE_THROWS_AS(aBool.getSymbol(), std::logic_error);

	REQUIRE_THROWS_AS(aNumber.getBool(), std::logic_error);
	REQUIRE_THROWS_AS(aNumber.getSymbol(), std::logic_error);

	REQUIRE_THROWS_AS(aSymbol.getBool(), std::logic_error);
	REQUIRE_THROWS_AS(aSymbol.getNumber(), std::logic_error);

}