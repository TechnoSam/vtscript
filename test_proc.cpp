// File: test_proc.cpp
// Author: Samuel McFalls

#include "catch.hpp"

#include <string>

#include "proc.hpp"

TEST_CASE("Tests the not procedure", "[proc]") {

	std::vector<Atom> args = { Atom(true) };
	REQUIRE(!notProc(args));

	args.clear();
	args = { Atom(false) };
	REQUIRE(notProc(args));

	args.clear();
	REQUIRE_THROWS(notProc(args));

	args = { Atom(false), Atom(true) };
	REQUIRE_THROWS(notProc(args));

	args.clear();
	args = { Atom(2.5) };
	REQUIRE_THROWS(notProc(args));

}

TEST_CASE("Tests the and procedure", "[proc]") {

	std::vector<Atom> args = { Atom(true) };
	REQUIRE(andProc(args));

	args.clear();
	args = { Atom(true), Atom(true), Atom(true) };
	REQUIRE(andProc(args));

	args.clear();
	args = { Atom(false), Atom(true), Atom(true) };
	REQUIRE(!andProc(args));

	args.clear();
	REQUIRE_THROWS(andProc(args));

	args.clear();
	args = { Atom(true), Atom(2.5) };
	REQUIRE_THROWS(andProc(args));

}

TEST_CASE("Tests the or procedure", "[proc]") {

	std::vector<Atom> args = { Atom(true) };
	REQUIRE(orProc(args));

	args.clear();
	args = { Atom(false), Atom(false), Atom(false) };
	REQUIRE(!orProc(args));

	args.clear();
	args = { Atom(false), Atom(false), Atom(true) };
	REQUIRE(orProc(args));

	args.clear();
	REQUIRE_THROWS(orProc(args));

	args.clear();
	args = { Atom(true), Atom(2.5) };
	REQUIRE_THROWS(orProc(args));

}

TEST_CASE("Tests the less than procedure", "[proc]") {

	std::vector<Atom> args = { Atom(1.0), Atom(2.0) };
	REQUIRE(ltProc(args));

	args.clear();
	args = { Atom(2.0), Atom(1.0) };
	REQUIRE(!ltProc(args));

	args.clear();
	args = { Atom(1.5), Atom(1.5) };
	REQUIRE(!ltProc(args));

	args.clear();
	REQUIRE_THROWS(ltProc(args));

	args = { Atom(1.0), Atom(2.0), Atom(3.0) };
	REQUIRE_THROWS(ltProc(args));

	args.clear();
	args = { Atom(1.0) };
	REQUIRE_THROWS(ltProc(args));

	args.clear();
	args = { Atom(1.0), Atom(false) };
	REQUIRE_THROWS(ltProc(args));

}

TEST_CASE("Tests the less than equal procedure", "[proc]") {

	std::vector<Atom> args = { Atom(1.0), Atom(2.0) };
	REQUIRE(lteProc(args));

	args.clear();
	args = { Atom(2.0), Atom(1.0) };
	REQUIRE(!lteProc(args));

	args.clear();
	args = { Atom(1.5), Atom(1.5) };
	REQUIRE(lteProc(args));

	args.clear();
	REQUIRE_THROWS(lteProc(args));

	args = { Atom(1.0), Atom(2.0), Atom(3.0) };
	REQUIRE_THROWS(lteProc(args));

	args.clear();
	args = { Atom(1.0) };
	REQUIRE_THROWS(lteProc(args));

	args.clear();
	args = { Atom(1.0), Atom(false) };
	REQUIRE_THROWS(lteProc(args));

}

TEST_CASE("Tests the greater than procedure", "[proc]") {

	std::vector<Atom> args = { Atom(1.0), Atom(2.0) };
	REQUIRE(!gtProc(args));

	args.clear();
	args = { Atom(2.0), Atom(1.0) };
	REQUIRE(gtProc(args));

	args.clear();
	args = { Atom(1.5), Atom(1.5) };
	REQUIRE(!gtProc(args));

	args.clear();
	REQUIRE_THROWS(gtProc(args));

	args = { Atom(1.0), Atom(2.0), Atom(3.0) };
	REQUIRE_THROWS(gtProc(args));

	args.clear();
	args = { Atom(1.0) };
	REQUIRE_THROWS(gtProc(args));

	args.clear();
	args = { Atom(1.0), Atom(false) };
	REQUIRE_THROWS(gtProc(args));

}

TEST_CASE("Tests the greater than equal procedure", "[proc]") {

	std::vector<Atom> args = { Atom(1.0), Atom(2.0) };
	REQUIRE(!gteProc(args));

	args.clear();
	args = { Atom(2.0), Atom(1.0) };
	REQUIRE(gteProc(args));

	args.clear();
	args = { Atom(1.5), Atom(1.5) };
	REQUIRE(gteProc(args));

	args.clear();
	REQUIRE_THROWS(gteProc(args));

	args = { Atom(1.0), Atom(2.0), Atom(3.0) };
	REQUIRE_THROWS(gteProc(args));

	args.clear();
	args = { Atom(1.0) };
	REQUIRE_THROWS(gteProc(args));

	args.clear();
	args = { Atom(1.0), Atom(false) };
	REQUIRE_THROWS(gteProc(args));

}

TEST_CASE("Tests the equal procedure", "[proc]") {

	std::vector<Atom> args = { Atom(1.0), Atom(2.0) };
	REQUIRE(!equalProc(args));

	args.clear();
	args = { Atom(2.0), Atom(1.0) };
	REQUIRE(!equalProc(args));

	args.clear();
	args = { Atom(1.5), Atom(1.5) };
	REQUIRE(equalProc(args));

	args.clear();
	REQUIRE_THROWS(equalProc(args));

	args = { Atom(1.0), Atom(2.0), Atom(3.0) };
	REQUIRE_THROWS(equalProc(args));

	args.clear();
	args = { Atom(1.0) };
	REQUIRE_THROWS(equalProc(args));

	args.clear();
	args = { Atom(1.0), Atom(false) };
	REQUIRE_THROWS(equalProc(args));

}

TEST_CASE("Tests the sum procedure", "[proc]") {

	std::vector<Atom> args = { Atom(2.5), Atom(3.5), Atom(4.0) };
	REQUIRE(sumProc(args) == 10.0);

	args.clear();
	args = { Atom(1.0) };
	REQUIRE(sumProc(args) == 1.0);

	args.clear();
	args = { Atom(-1.0), Atom(1.0) };
	REQUIRE(sumProc(args) == 0.0);

	args.clear();
	REQUIRE_THROWS(sumProc(args));

	args = { Atom(1.0), Atom(2.0), Atom(true) };
	REQUIRE_THROWS(sumProc(args));

	args.clear();
	args = { Atom(std::string("Test")), Atom(), Atom(false) };
	REQUIRE_THROWS(sumProc(args));

}

TEST_CASE("Tests the sub procedure", "[proc]") {

	std::vector<Atom> args{ Atom(117.0) };
	REQUIRE(subProc(args) == -117.0);

	args.clear();
	args = { Atom(-42.42) };
	REQUIRE(subProc(args) == 42.42);

	args.clear();
	args = { Atom(32.8), Atom(12.1) };
	REQUIRE(subProc(args) == (32.8 - 12.1));

	args.clear();
	args = { Atom(12.1), Atom(32.8) };
	REQUIRE(subProc(args) == (12.1 - 32.8));

	args.clear();
	REQUIRE_THROWS(subProc(args));

	args = { Atom(1.0), Atom(2.0), Atom(3.0) };
	REQUIRE_THROWS(subProc(args));

	args.clear();
	args = { Atom(true), Atom(false) };
	REQUIRE_THROWS(subProc(args));

	args.clear();
	args = { Atom(true) };
	REQUIRE_THROWS(subProc(args));

}

TEST_CASE("Tests the mult procedure", "[proc]") {

	std::vector<Atom> args = { Atom(2.2), Atom(3.3), Atom(4.4) };
	REQUIRE(multProc(args) == (2.2 * 3.3 * 4.4));

	args.clear();
	args = { Atom(2.2), Atom(-3.3), Atom(4.4) };
	REQUIRE(multProc(args) == (2.2 * -3.3 * 4.4));

	args.clear();
	args = { Atom(2.2), Atom(-3.3), Atom(-4.4) };
	REQUIRE(multProc(args) == (2.2 * -3.3 * -4.4));

	args.clear();
	args = { Atom(123.456) };
	REQUIRE(multProc(args) == 123.456);

	args.clear();
	REQUIRE_THROWS(multProc(args));

	args = { Atom(true), Atom(false) };
	REQUIRE_THROWS(multProc(args));

}

TEST_CASE("Tests the div procedure", "[proc]") {

	std::vector<Atom> args = { Atom(1.0), Atom(2.0) };
	REQUIRE(divProc(args) == 0.5);

	args.clear();
	args = { Atom(0.5), Atom(0.5) };
	REQUIRE(divProc(args) == 1.0);

	args.clear();
	args = { Atom(-0.5), Atom(0.5) };
	REQUIRE(divProc(args) == -1.0);

	args.clear();
	args = { Atom(-0.5), Atom(-0.5) };
	REQUIRE(divProc(args) == 1.0);

	args.clear();
	args = { Atom(0.0), Atom(50.234) };
	REQUIRE(divProc(args) == 0);

	args.clear();
	REQUIRE_THROWS(divProc(args));

	args = { Atom(1.0) };
	REQUIRE_THROWS(divProc(args));

	args.clear();
	args = { Atom(1.0), Atom(2.0), Atom(3.0) };
	REQUIRE_THROWS(divProc(args));

	args.clear();
	args = { Atom(true), Atom(false) };
	REQUIRE_THROWS(divProc(args));

}