#pragma once
#include "Node.h"
#include <string>

using namespace std;

class BinaryTree {
	Node* root;
public:
	BinaryTree(const string& formula);

	void printPrefix();

	~BinaryTree();
};