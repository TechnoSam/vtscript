// File: ASTNode.cpp

#include "ASTNode.hpp"

ASTNode::ASTNode() {

	parent = nullptr;
	data = "";

}

ASTNode::~ASTNode() {

}

ASTNode* ASTNode::getParent() {

	return parent;

}

ASTNode* ASTNode::lastChild() {

	return children.at(children.size() - 1);

}

void ASTNode::appendChild(std::string data) {

	ASTNode* child = new ASTNode();
	child->data = data;
	child->parent = this;
	children.push_back(child);

}