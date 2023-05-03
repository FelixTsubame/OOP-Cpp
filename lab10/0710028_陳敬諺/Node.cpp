#include "Node.h"
int Node::getValue() {
	return value;
}
Node* Node::getLchild() {
	return lchild;
}
Node* Node::getRchild() {
	return rchild;
}
Node* Node::getParent() {
	return parent;
}
void Node::setLchild(Node* node) {
	lchild = node;
}
void Node::setRchild(Node* node) {
	rchild = node;
}
void Node::setParent(Node* node) {
	parent = node;
}
void Node::setValue(int v) {
	value = v;
}