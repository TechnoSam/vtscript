// File: test_environment.cpp
// Author: Samuel McFalls

#include "catch.hpp"

#include "environment.hpp"

TEST_CASE("Tests the Environment constructor", "[environment]") {

	Environment env;
	EnvEntry result;

	EnvEntry::fptrBool notFptr = notProc;
	EnvEntry::fptrBool andFptr = andProc;
	EnvEntry::fptrBool orFptr = orProc;

	EnvEntry::fptrBool ltFptr = ltProc;
	EnvEntry::fptrBool lteFptr = lteProc;
	EnvEntry::fptrBool gtFptr = gtProc;
	EnvEntry::fptrBool gteFptr = gteProc;
	EnvEntry::fptrBool equalFptr = equalProc;

	EnvEntry::fptrNumber sumFptr = sumProc;
	EnvEntry::fptrNumber subFptr = subProc;
	EnvEntry::fptrNumber multFptr = multProc;
	EnvEntry::fptrNumber divFptr = divProc;

	REQUIRE(env.exists("pi"));
	result = env.fetch("pi");
	REQUIRE(result.getType() == EnvEntry::Type::NUMBER);
	REQUIRE(result.getNumber() == atan2(0, -1));

	REQUIRE(env.exists("not"));
	result = env.fetch("not");
	REQUIRE(result.getType() == EnvEntry::Type::FPTR_BOOL);
	REQUIRE(result.getFptrBool() == notFptr);

	REQUIRE(env.exists("and"));
	result = env.fetch("and");
	REQUIRE(result.getType() == EnvEntry::Type::FPTR_BOOL);
	REQUIRE(result.getFptrBool() == andFptr);

	REQUIRE(env.exists("or"));
	result = env.fetch("or");
	REQUIRE(result.getType() == EnvEntry::Type::FPTR_BOOL);
	REQUIRE(result.getFptrBool() == orFptr);

	REQUIRE(env.exists("<"));
	result = env.fetch("<");
	REQUIRE(result.getType() == EnvEntry::Type::FPTR_BOOL);
	REQUIRE(result.getFptrBool() == ltFptr);

	REQUIRE(env.exists("<="));
	result = env.fetch("<=");
	REQUIRE(result.getType() == EnvEntry::Type::FPTR_BOOL);
	REQUIRE(result.getFptrBool() == lteFptr);

	REQUIRE(env.exists(">"));
	result = env.fetch(">");
	REQUIRE(result.getType() == EnvEntry::Type::FPTR_BOOL);
	REQUIRE(result.getFptrBool() == gtFptr);

	REQUIRE(env.exists(">="));
	result = env.fetch(">=");
	REQUIRE(result.getType() == EnvEntry::Type::FPTR_BOOL);
	REQUIRE(result.getFptrBool() == gteFptr);

	REQUIRE(env.exists("="));
	result = env.fetch("=");
	REQUIRE(result.getType() == EnvEntry::Type::FPTR_BOOL);
	REQUIRE(result.getFptrBool() == equalFptr);

	REQUIRE(env.exists("+"));
	result = env.fetch("+");
	REQUIRE(result.getType() == EnvEntry::Type::FPTR_NUMBER);
	REQUIRE(result.getFptrNumber() == sumFptr);

	REQUIRE(env.exists("-"));
	result = env.fetch("-");
	REQUIRE(result.getType() == EnvEntry::Type::FPTR_NUMBER);
	REQUIRE(result.getFptrNumber() == subFptr);

	REQUIRE(env.exists("*"));
	result = env.fetch("*");
	REQUIRE(result.getType() == EnvEntry::Type::FPTR_NUMBER);
	REQUIRE(result.getFptrNumber() == multFptr);

	REQUIRE(env.exists("/"));
	result = env.fetch("/");
	REQUIRE(result.getType() == EnvEntry::Type::FPTR_NUMBER);
	REQUIRE(result.getFptrNumber() == divFptr);

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
	REQUIRE(result.getBool());

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
	REQUIRE(!env.exists("DNE"));
	REQUIRE_THROWS(env.fetch("DNE"));

}