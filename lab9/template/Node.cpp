#include "Node.h"
string Node::getValue() {
	return value;
}

Node* Node::getLchild() {
	return lchild;
}

Node* Node::getRchild() {
	return rchild;
}

void Node::setLchild(Node* node) {
	lchild = node;
}

void Node::setRchild(Node* node) {
	rchild = node;
}