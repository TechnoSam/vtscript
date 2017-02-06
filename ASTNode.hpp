// File: ASTNode.hpp

#ifndef ASTNODE_H
#define ASTNODE_H

#include <vector>
#include <string>

class ASTNode {

public:

	ASTNode();

	~ASTNode();

	ASTNode getParent();

	ASTNode lastChild();

	void appendChild(std::string data);

private:

	ASTNode* parent;

	std::vector<ASTNode> children;

	std::string data;

};

#endif