#include <iostream>
#include <fstream>
#include "BT.h"
#include "Node.h"
#include <string>
#include <queue>
using namespace std;
void inOrderTraverse(Node* root) {
	// implement inorder traversal
	if (root != NULL)
	{
		inOrderTraverse(root->getLchild());
		cout << root->getValue() << " ";
		inOrderTraverse(root->getRchild());
	}
}
void preOrderTraverse(Node* root) {
	//implement preorder traversal
	if (root != NULL)
	{
		cout << root->getValue() << " ";
		preOrderTraverse(root->getLchild());
		preOrderTraverse(root->getRchild());
	}
}

void postOrderTraverse(Node* root) {
	//implement postorder traversal
	if (root != NULL)
	{
		postOrderTraverse(root->getLchild());
		postOrderTraverse(root->getRchild());
		cout << root->getValue() << " ";
	}
}
int main() {

	// create a binary tree to store the input data
	// then print the data using inorder, preorder, postorder traversal
	fstream input("input.txt");
	BT treetra;
	while (!input.eof())
	{
		string in;
		input >> in;
		Node* nn = new Node(in);
		treetra.insert(nn);
	}
	cout << "in-order:\n";
	inOrderTraverse(treetra.getRoot());
	cout << endl;
	cout << "pre-order:\n";
	preOrderTraverse(treetra.getRoot());
	cout << endl;
	cout << "post-order:\n";
	postOrderTraverse(treetra.getRoot());
	cout << endl;
	system("pause");
	return 0;

}