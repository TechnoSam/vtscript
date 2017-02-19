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
	std::stringstream ss(prog);
	REQUIRE_NOTHROW(tkns = tkn.tokenize(ss));
	tkns_check = { "(", "if", "(", "<", "a", "b", ")", "b", ")", "a" };
	REQUIRE(tkns == tkns_check);

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

}