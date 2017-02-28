// File: proc.hpp
// Author: Samuel McFalls

#include <vector>

#include "interpreter_semantic_error.hpp"
#include "atom.hpp"

// unary expression of Booleans
// @param args The arguments to the procedure. Required BOOL type
// @return The logical negation of the argument
// @throw InterpreterSemanticError if improper number of arguments
// @throw InterpreterSemanticError if arguments are of incorrect type
bool notProc(std::vector<Atom> args);

// m-ary expression of Booleans There is no short circuit.
// All expressions are evaluated.
// @param args The arguments to the procedure. Required BOOL type
// @return The logical conjunction of the arguments
// @throw InterpreterSemanticError if improper number of arguments
// @throw InterpreterSemanticError if arguments are of incorrect type
bool andProc(std::vector<Atom> args);

// m-ary expression of Booleans
// There is no short circuit. All expressions are evaluated.
// @param args The arguments to the procedure. Required BOOL type
// @return The logical disjunction of the arguments
// @throw InterpreterSemanticError if improper number of arguments
// @throw InterpreterSemanticError if arguments are of incorrect type
bool orProc(std::vector<Atom> args);

// binary expression of Numbers
// @param args The arguments to the procedure. Required NUMBER type
// @return True if the first argument is numerically less than the
// second, else False
// @throw InterpreterSemanticError if improper number of arguments
// @throw InterpreterSemanticError if arguments are of incorrect type
bool ltProc(std::vector<Atom> args);

// binary expression of Numbers
// @param args The arguments to the procedure. Required NUMBER type
// @return True if the first argument is numerically less than or equal
// to the second, else False
// @throw InterpreterSemanticError if improper number of arguments
// @throw InterpreterSemanticError if arguments are of incorrect type
bool lteProc(std::vector<Atom> args);

// binary expression of Numbers
// @param args The arguments to the procedure. Required NUMBER type
// @return True if the first argument is numerically greater than the second, else False
// @throw InterpreterSemanticError if improper number of arguments
// @throw InterpreterSemanticError if arguments are of incorrect type
bool gtProc(std::vector<Atom> args);

// binary expression of Numbers
// @param args The arguments to the procedure. Required NUMBER type
// @return True if the first argument is numerically greater than or equal to the second, else False
// @throw InterpreterSemanticError if improper number of arguments
// @throw InterpreterSemanticError if arguments are of incorrect type
bool gteProc(std::vector<Atom> args);

// binary expression of Numbers
// @param args The arguments to the procedure. Required NUMBER type
// @return True if the first argument is numerically equal to the second,, else False
// @throw InterpreterSemanticError if improper number of arguments
// @throw InterpreterSemanticError if arguments are of incorrect type
bool equalProc(std::vector<Atom> args);

// m-ary expression of Numbers
// @param args The arguments to the procedure. Required NUMBER type
// @return the sum of the arguments
// @throw InterpreterSemanticError if improper number of arguments
// @throw InterpreterSemanticError if arguments are of incorrect type
double sumProc(std::vector<Atom> args);

// unary/binary expression of Numbers
// @param args The arguments to the procedure. Required NUMBER type
// @return (if unary) the negative of the argument
// (if binary) the first argument minus the second
// @throw InterpreterSemanticError if improper number of arguments
// @throw InterpreterSemanticError if arguments are of incorrect type
double subProc(std::vector<Atom> args);

// m-ary expression of Number arguments
// @param args The arguments to the procedure. Required NUMBER type
// @return the product of the arguments
// @throw InterpreterSemanticError if improper number of arguments
// @throw InterpreterSemanticError if arguments are of incorrect type
double multProc(std::vector<Atom> args);

// binary expression of Numbers
// @param args The arguments to the procedure. Required NUMBER type
// @return the first argument divided by the second
// @throw InterpreterSemanticError if improper number of arguments
// @throw InterpreterSemanticError if arguments are of incorrect type
double divProc(std::vector<Atom> args);