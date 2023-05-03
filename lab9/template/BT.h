#pragma once
#include "iostream"
#include "Node.h"
#include <queue>
using namespace std;
class BT {
public:
	BT() {
		root = NULL;
	}
	void insert(Node* node);
	Node* getRoot();
private:
	Node * root;
	queue<Node*> queue;
};
