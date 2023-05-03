#pragma once
#include "iostream"
#include "Node.h"
#include <string>
class BST {
public:
	BST() {
		root = NULL;
	}
	void insert(Node* node);
	void deletion(int value);
    Node* search(int value);
	Node* getRoot();
	Node* successor(Node* current);
	Node* leftmost(Node* current);
	void inOrderTraverse(Node* root);
	void preOrderTraverse(Node* root);
private:
	Node* root;
};
