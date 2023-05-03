#pragma once
#include <iostream>
#include <string>
using namespace std;

class Node {
public:
	Node(string val) {
		value = val;
		lchild = NULL;
		rchild = NULL;
	}
	string getValue();
	Node* getLchild();
	Node* getRchild();

	void setLchild(Node* node);
	void setRchild(Node* node);
private:
	string value;
	Node* lchild;
	Node* rchild;
};
