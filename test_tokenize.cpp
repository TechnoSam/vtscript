// File: test_tokenize.cpp
// Author: Samuel McFalls

#include "catch.hpp"

#include "tokenize.hpp"

TEST_CASE("Tests tokenizer method", "[tokenize]") {

	Tokenizer tkn;
	
	std::string prog = "(begin\t(define    a    1)\t(define (b) pi)\t(if (< a b) b a))";
	std::stringstream ss1(prog);

	std::vector<std::string> tkns;
	REQUIRE_NOTHROW(tkns = tkn.tokenize(ss1));
	std::vector<std::string> tkns_check = {"(", "begin", "(", "define", "a", "1", ")",
		"(", "define", "(", "b", ")", "pi", ")",
		"(", "if", "(", "<", "a", "b", ")", "b", "a", ")", ")"};
	REQUIRE(tkns == tkns_check);

	// Passes tokenization but not building
	prog = "((+ 1 2))";
	std::stringstream ss2(prog);
	REQUIRE_NOTHROW(tkns = tkn.tokenize(ss2));

	// Passes tokenization but not building
	prog = "()";
	std::stringstream ss3(prog);
	REQUIRE_NOTHROW(tkns = tkn.tokenize(ss3));

	prog = "(+ 1 2";
	std::stringstream ss4(prog);
	REQUIRE_THROWS(tkns = tkn.tokenize(ss4));

	prog = "+ 1 2)";
	std::stringstream ss5(prog);
	REQUIRE_THROWS(tkns = tkn.tokenize(ss5));

	prog = "(if (< a b) b )a";
	std::stringstream ss6(prog);
	REQUIRE_NOTHROW(tkns = tkn.tokenize(ss6));
	tkns_check = { "(", "if", "(", "<", "a", "b", ")", "b", ")", "a" };
	REQUIRE(tkns == tkns_check);


	// Passes tokenization but not building
	prog = "(begin((4)))";
	std::stringstream ss7(prog);
	REQUIRE_NOTHROW(tkns = tkn.tokenize(ss7));
	REQUIRE_THROWS(tkn.buildAST(tkns));
}

TEST_CASE("Tests ASTBuilder method", "[tokenize]") {

	Tokenizer tkn;

	std::string prog = "(begin\t(define    a    1)\t(define (b) pi)\t(if (< a b) b a))";
	std::stringstream ss(prog);

	std::vector<std::string> tkns;

	REQUIRE_NOTHROW(tkns = tkn.tokenize(ss));

	Expression tree;

	REQUIRE_NOTHROW(tree = tkn.buildAST(tkns));
	REQUIRE(tree.getChildren().size() == 3);
	Expression defineA = tree.getChildren().at(0);
	Expression defineB = tree.getChildren().at(1);
	Expression ifNode = tree.getChildren().at(2);

	REQUIRE(defineA.getChildren().size() == 2);
	Expression a = defineA.getChildren().at(0);
	Expression one = defineA.getChildren().at(1);
	REQUIRE(a.getChildren().empty());
	REQUIRE(a.getAtom().getType() == Atom::Type::SYMBOL);
	REQUIRE(a.getAtom().getSymbol() == "a");
	REQUIRE(one.getChildren().empty());
	REQUIRE(one.getAtom().getType() == Atom::Type::NUMBER);
	REQUIRE(one.getAtom().getNumber() == 1.0);

	REQUIRE(defineB.getChildren().size() == 2);
	Expression b = defineB.getChildren().at(0);
	Expression pi = defineB.getChildren().at(1);
	REQUIRE(b.getChildren().empty());
	REQUIRE(b.getAtom().getType() == Atom::Type::SYMBOL);
	REQUIRE(b.getAtom().getSymbol() == "b");
	REQUIRE(pi.getChildren().empty());
	REQUIRE(pi.getAtom().getType() == Atom::Type::SYMBOL);
	REQUIRE(pi.getAtom().getSymbol() == "pi");

	REQUIRE(ifNode.getChildren().size() == 3);
	Expression lt = ifNode.getChildren().at(0);
	Expression ifB = ifNode.getChildren().at(1);
	Expression ifA = ifNode.getChildren().at(2);

	REQUIRE(lt.getChildren().size() == 2);
	Expression ltA = lt.getChildren().at(0);
	Expression ltB = lt.getChildren().at(1);

	REQUIRE(ltA.getChildren().empty());
	REQUIRE(ltA.getAtom().getType() == Atom::Type::SYMBOL);
	REQUIRE(ltA.getAtom().getSymbol() == "a");
	REQUIRE(ltB.getChildren().empty());
	REQUIRE(ltB.getAtom().getType() == Atom::Type::SYMBOL);
	REQUIRE(ltB.getAtom().getSymbol() == "b");

	REQUIRE(ifB.getChildren().empty());
	REQUIRE(ifB.getAtom().getType() == Atom::Type::SYMBOL);
	REQUIRE(ifB.getAtom().getSymbol() == "b");

	REQUIRE(ifA.getChildren().empty());
	REQUIRE(ifA.getAtom().getType() == Atom::Type::SYMBOL);
	REQUIRE(ifA.getAtom().getSymbol() == "a");

	// Passes tokenization but not building
	prog = "((+ 1 2))";
	std::stringstream ss2(prog);
	REQUIRE_NOTHROW(tkns = tkn.tokenize(ss2));
	REQUIRE_THROWS(tkn.buildAST(tkns));

	// Passes tokenization but not building
	prog = "()";
	std::stringstream ss3(prog);
	REQUIRE_NOTHROW(tkns = tkn.tokenize(ss3));
	REQUIRE_THROWS(tkn.buildAST(tkns));

	// Test exponential parsing
	prog = "(32.e-1)";
	std::stringstream ss4(prog);
	REQUIRE_NOTHROW(tkns = tkn.tokenize(ss4));
	REQUIRE_NOTHROW(tkn.buildAST(tkns));

	prog = "(if (< a b) b )a";
	std::stringstream ss6(prog);
	REQUIRE_NOTHROW(tkns = tkn.tokenize(ss6));
	REQUIRE_THROWS(tkn.buildAST(tkns));
	
}