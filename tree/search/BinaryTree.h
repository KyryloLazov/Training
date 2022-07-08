#pragma once
#include "Node.h"

class Binarytree {
	Node* root;
	void recursionPrint(Node* toPrint, int& counter);
public:
	Binarytree();

	void addNode(int value);
	void removeNode(int value);
	Node* findNode(int value);

	int print();
	void generate(int size, int min, int max);

	~Binarytree();
};