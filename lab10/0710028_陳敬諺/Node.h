#pragma once
#include <iostream>
#include <string>
class Node {
public:
	Node(int val) {
		value = val;
		lchild = NULL;
		rchild = NULL;
		parent = NULL;
	}
	int getValue();
	Node* getLchild();
	Node* getRchild();
	Node* getParent();

	void setLchild(Node* node);
	void setRchild(Node* node);
	void setParent(Node* node);
	void setValue(int v);
private:
	int value;
	Node* lchild;
	Node* rchild;
	Node* parent;
};
