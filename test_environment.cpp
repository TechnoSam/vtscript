// File: test_environment.cpp
// Author: Samuel McFalls

#include "catch.hpp"

#include "environment.hpp"

TEST_CASE("Tests the Environment constructor", "[environment]") {

	Environment env;
	EnvEntry result;

	result = env.fetch("pi");
	REQUIRE(result.getType() == EnvEntry::Type::NUMBER);
	REQUIRE(result.getNumber() == atan2(0, -1));

	result = env.fetch("not");
	REQUIRE(result.getType() == EnvEntry::Type::FPTR_BOOL);
	//REQUIRE(result.getFptrBool() == notProc);

	result = env.fetch("and");
	REQUIRE(result.getType() == EnvEntry::Type::FPTR_BOOL);
	//REQUIRE(result.getFptrBool() == andProc);

	result = env.fetch("or");
	REQUIRE(result.getType() == EnvEntry::Type::FPTR_BOOL);
	//REQUIRE(result.getFptrBool() == orProc);

	result = env.fetch("<");
	REQUIRE(result.getType() == EnvEntry::Type::FPTR_BOOL);
	//REQUIRE(result.getFptrBool() == ltProc);

	result = env.fetch("<=");
	REQUIRE(result.getType() == EnvEntry::Type::FPTR_BOOL);
	//REQUIRE(result.getFptrBool() == lteProc);

	result = env.fetch(">");
	REQUIRE(result.getType() == EnvEntry::Type::FPTR_BOOL);
	//REQUIRE(result.getFptrBool() == gtProc);

	result = env.fetch(">=");
	REQUIRE(result.getType() == EnvEntry::Type::FPTR_BOOL);
	//REQUIRE(result.getFptrBool() == gteProc);

	result = env.fetch("=");
	REQUIRE(result.getType() == EnvEntry::Type::FPTR_BOOL);
	//REQUIRE(result.getFptrBool() == equalProc);

	result = env.fetch("+");
	REQUIRE(result.getType() == EnvEntry::Type::FPTR_NUMBER);
	//REQUIRE(result.getFptrNumber() == sumProc);

	result = env.fetch("-");
	REQUIRE(result.getType() == EnvEntry::Type::FPTR_NUMBER);
	//REQUIRE(result.getFptrNumber() == subProc);

	result = env.fetch("*");
	REQUIRE(result.getType() == EnvEntry::Type::FPTR_NUMBER);
	//REQUIRE(result.getFptrNumber() == multProc);

	result = env.fetch("/");
	REQUIRE(result.getType() == EnvEntry::Type::FPTR_NUMBER);
	//REQUIRE(result.getFptrNumber() == divProc);

}

TEST_CASE("Test valid defining and fetching in the Environment", "[environment]") {

	Environment env;
	EnvEntry entry;
	EnvEntry result;

	entry = EnvEntry(true);
	REQUIRE_NOTHROW(env.define("Bool", entry));

	entry = EnvEntry(117.6);
	REQUIRE_NOTHROW(env.define("Number", entry));

	EnvEntry::fptrBool fBool = notProc;
	entry = EnvEntry(fBool);
	REQUIRE_NOTHROW(env.define("FBool", entry));

	EnvEntry::fptrNumber fNumber = sumProc;
	entry = EnvEntry(fNumber);
	REQUIRE_NOTHROW(env.define("FNumber", entry));

	REQUIRE_NOTHROW(env.fetch("Bool"));
	result = env.fetch("Bool");
	REQUIRE(result.getType() == EnvEntry::Type::BOOL);
	REQUIRE(result.getBool() == true);

	REQUIRE_NOTHROW(env.fetch("Number"));
	result = env.fetch("Number");
	REQUIRE(result.getType() == EnvEntry::Type::NUMBER);
	REQUIRE(result.getNumber() == 117.6);

	REQUIRE_NOTHROW(env.fetch("FBool"));
	result = env.fetch("FBool");
	REQUIRE(result.getType() == EnvEntry::Type::FPTR_BOOL);
	//REQUIRE(result.getFptrBool() == fBool);

	REQUIRE_NOTHROW(env.fetch("FNumber"));
	result = env.fetch("FNumber");
	REQUIRE(result.getType() == EnvEntry::Type::FPTR_NUMBER);
	//REQUIRE(result.getFptrNumber() == fNumber);
}

TEST_CASE("Test invalid defining and fetching in the Environment", "[environment]") {

	Environment env;
	EnvEntry entry;
	EnvEntry result;

	entry = EnvEntry(true);
	REQUIRE_NOTHROW(env.define("Bool", entry));
	REQUIRE_THROWS(env.define("Bool", entry));

	REQUIRE_NOTHROW(env.fetch("Bool"));
	REQUIRE_THROWS(env.fetch("DNE"));

}