#pragma once
#include "Node.h"

class BinaryTree {
	Node* root;
public:
	BinaryTree();
	BinaryTree(int* arr, int size);

	void addNode(int value);
	Node* findNode(int value);
	void deleteNode(int value);

	void printStraight();
	void printReverse();
	void printSymmetrical();

	~BinaryTree();
};