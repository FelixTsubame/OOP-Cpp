#include "BT.h"
#include <vector>
#include <queue>
using namespace std;
void BT::insert(Node* insertNode) {
	//implement the insert function here
	if (queue.empty())
	{
		queue.push(insertNode);
		root = insertNode;
	}
	else
	{
		queue.push(insertNode);
		if (queue.front()->getLchild()==NULL)
		{
			queue.front()->setLchild(insertNode);
		}
		else
		{
			queue.front()->setRchild(insertNode);
			queue.pop();
		}
	}
}


Node* BT::getRoot() {
	return root;
}