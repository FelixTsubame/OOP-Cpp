#include "BST.h"
#include <vector>
#include <string>
#include <iostream>
void BST::insert(Node* insertNode) {
	if (root == NULL) {
		root =insertNode;
	}
	else {
		Node* curr = root;
		Node* parent = root;
		while (curr != NULL) {
			parent = curr;
			if (insertNode->getValue() <= curr->getValue( )) {
				curr = curr->getLchild();
			}
			else {
				curr = curr->getRchild();
			}
		 }
		if (insertNode->getValue() <= parent->getValue()) {
			parent->setLchild(insertNode);
		}
		else {
			parent->setRchild(insertNode);
		}
		insertNode->setParent(parent);
	}
}
void BST::deletion(int value) {
	// Implement the deletion here.
	// You may need to implement and use the successor and the leftmost function.
	// You can do any modification you want.
	Node *de_n = search(value);

	if (!de_n)
	{
		std::cout << "no value of " << value << " in the tree!\n";
		return;
	}

	Node *de_n_c = 0;
	Node *suc = 0;

	if (de_n->getLchild() == NULL || de_n->getRchild() == NULL)
	{
		suc = de_n;
	}
	else
	{
		suc = successor(de_n);
	}

	if (suc->getLchild() != NULL)
		de_n_c = suc->getLchild();
	else
		de_n_c = suc->getRchild();

	if (de_n_c != NULL)
		de_n_c->setParent(suc->getParent());
	
	if (suc->getParent() == NULL)
		root = de_n_c;
	else if (suc->getParent()->getLchild() == suc)
		suc->getParent()->setLchild(de_n_c);
	else
		suc->getParent()->setRchild(de_n_c);

	if (suc != de_n)
	{
		de_n->setValue(suc->getValue());
	}
	delete suc;
	suc = 0;

}
Node* BST::successor(Node *current) {
	// You may need to implement successor function here.
	if (current->getRchild() != NULL)
	{
		return leftmost(current->getRchild());
	}

	Node *suc = current->getParent();
	while (suc!=NULL&&suc->getRchild()==current)
	{
		current = current->getParent();
		suc = suc->getParent();
	}
	return suc;
}
Node* BST::leftmost(Node *current) {
	// You may need to implement leftmost function here.
	if (current->getLchild() != NULL)
	{
		return leftmost(current->getLchild());
	}
	else
	{
		return current;
	}
}
Node* BST::search(int value) {
	
	Node* curr = root;
	int index = 1;
	bool found = false;
	while (curr != NULL) {
		if (value == curr->getValue()) {
			return curr;
		}
		else if (value < curr->getValue()) {
			index = index * 2;
			curr = curr->getLchild();
		}
		else {
			index = index * 2 + 1;
			curr = curr->getRchild();
		}
	}
	return NULL;
}

Node* BST::getRoot() {
	return root;
}

void BST::inOrderTraverse(Node* root) {
	if (root != NULL) {
		inOrderTraverse(root->getLchild());
		std::cout << root->getValue() << " ";
		inOrderTraverse(root->getRchild());
	}
}
void BST::preOrderTraverse(Node* root) {
	if (root != NULL) {
		std::cout << root->getValue() << " ";
		preOrderTraverse(root->getLchild());
		preOrderTraverse(root->getRchild());
	}
}