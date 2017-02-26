// File: test_EnvEntry.cpp
// Author: Samuel McFalls

#include "catch.hpp"

#include "env_entry.hpp"

#include <vector>
#include <string>

// Returns true if odd number of args, false otherwise
bool boolFunc(std::vector<Atom> args) {

	return (args.size() % 2 == 1);

}

// Returns the number of args
double numberFunc(std::vector<Atom> args) {

	return args.size();

}

TEST_CASE("Tests the EnvEntry constructors", "[enventry]") {

	EnvEntry eNone = EnvEntry();
	EnvEntry eBool = EnvEntry(true);
	EnvEntry eNumber = EnvEntry(2.5);
	EnvEntry::fptrBool boolFuncPtr = boolFunc;
	EnvEntry eBoolFunc = EnvEntry(boolFuncPtr);
	EnvEntry::fptrNumber numFuncPtr = numberFunc;
	EnvEntry eNumFunc = EnvEntry(numFuncPtr);

	REQUIRE(eNone.getType() == EnvEntry::Type::NONE);
	REQUIRE(eBool.getType() == EnvEntry::Type::BOOL);
	REQUIRE(eNumber.getType() == EnvEntry::Type::NUMBER);
	REQUIRE(eBoolFunc.getType() == EnvEntry::Type::FPTR_BOOL);
	REQUIRE(eNumFunc.getType() == EnvEntry::Type::FPTR_NUMBER);

	std::vector<Atom> args1;
	args1.push_back(Atom(1.0));
	args1.push_back(Atom(2.0));
	args1.push_back(Atom(3.0));

	REQUIRE(eBool.getBool());
	REQUIRE(eNumber.getNumber() == 2.5);
	REQUIRE(eBoolFunc.getFptrBool()(args1));
	REQUIRE(eNumFunc.getFptrNumber()(args1) == 3.0);

}

TEST_CASE("Tests exception throwing for invalid access on EnvEntries", "[enventry]") {

	EnvEntry eNone = EnvEntry();
	EnvEntry eBool = EnvEntry(true);
	EnvEntry eNumber = EnvEntry(2.5);
	EnvEntry::fptrBool boolFuncPtr = boolFunc;
	EnvEntry eBoolFunc = EnvEntry(boolFuncPtr);
	EnvEntry::fptrNumber numFuncPtr = numberFunc;
	EnvEntry eNumFunc = EnvEntry(numFuncPtr);

	REQUIRE_THROWS_AS(eNone.getBool(), std::logic_error);
	REQUIRE_THROWS_AS(eNone.getNumber(), std::logic_error);
	REQUIRE_THROWS_AS(eNone.getFptrBool(), std::logic_error);
	REQUIRE_THROWS_AS(eNone.getFptrNumber(), std::logic_error);

	REQUIRE_THROWS_AS(eBool.getNumber(), std::logic_error);
	REQUIRE_THROWS_AS(eBool.getFptrBool(), std::logic_error);
	REQUIRE_THROWS_AS(eBool.getFptrNumber(), std::logic_error);

	REQUIRE_THROWS_AS(eNumber.getBool(), std::logic_error);
	REQUIRE_THROWS_AS(eNumber.getFptrBool(), std::logic_error);
	REQUIRE_THROWS_AS(eNumber.getFptrNumber(), std::logic_error);

	REQUIRE_THROWS_AS(eBoolFunc.getBool(), std::logic_error);
	REQUIRE_THROWS_AS(eBoolFunc.getNumber(), std::logic_error);
	REQUIRE_THROWS_AS(eBoolFunc.getFptrNumber(), std::logic_error);

	REQUIRE_THROWS_AS(eNumFunc.getBool(), std::logic_error);
	REQUIRE_THROWS_AS(eNumFunc.getNumber(), std::logic_error);
	REQUIRE_THROWS_AS(eNumFunc.getFptrBool(), std::logic_error);

}