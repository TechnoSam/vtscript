// File: ASTNode.hpp

#ifndef ASTNODE_H
#define ASTNODE_H

#include <vector>
#include <string>

class ASTNode {

public:

	ASTNode();

	ASTNode::ASTNode(std::string dataInit);

	~ASTNode();

	ASTNode* getParent();

	ASTNode* lastChild();

	std::vector<ASTNode*> getChildren();

	void appendChild(std::string data);

	std::string getData();

private:

	ASTNode* parent;

	std::vector<ASTNode*> children;

	std::string data;

};

#endif