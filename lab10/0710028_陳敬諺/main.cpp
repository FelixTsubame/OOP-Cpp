#include <iostream>
#include <fstream>
#include "BST.h"
#include "Node.h"
#include <string>
using namespace std;
int main() {
	int inputSize = 0;
	string inputData;
	ifstream file;
	file.open("./BST_input_file.txt", ios::in);
	if (!file) {
		cerr << "Failed to open file" << endl;
	}
	
	BST bst = BST();
	while (file >> inputData && inputData != "D") {
		Node* insertNode = new Node(std::stoi(inputData));
		bst.insert(insertNode);
	}

	while (file.peek() != EOF) {
		while (file >> inputData && inputData != "D") {
			bst.deletion(std::stoi(inputData));
			//cout << "yes ";
		}
		cout << "inOrder: ";
		bst.inOrderTraverse(bst.getRoot());
		cout << endl;
		cout << "preOrder: ";
		bst.preOrderTraverse(bst.getRoot());
		cout << endl;
	}
	
	system("pause");
	return 0;

}