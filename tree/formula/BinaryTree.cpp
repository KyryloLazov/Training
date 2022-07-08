#include "BinaryTree.h"
#include <iostream>

using namespace std;

int findHighestPriorityIndex(string s) {
	for (size_t i = 0; i < s.length(); i++)
	{
		if (s[i] == '+' or s[i] == '-') return i;
	}
	for (size_t i = 0; i < s.length(); i++)
	{
		if (s[i] == '*' or s[i] == '/') return i;
	}
	return -1;
}

void recursionAdd(Node* node, string formula) {
	int index = findHighestPriorityIndex(formula);
	if (index == -1) {
		node->value = formula[0];
		return;
	}

	string part1, part2;
	part1 = formula.substr(0, index);
	part2 = formula.substr(index + 1, formula.length());

	node->value = formula[index];
	node->left = new Node(node);
	node->right = new Node(node);

	recursionAdd(node->left, part1);
	recursionAdd(node->right, part2);
}

BinaryTree::BinaryTree(const string& formula)
{
	const string validSymbols = "+-*/";

	if (!isdigit(formula[0])) throw exception("First symbol must be digit");

	for (size_t i = 0; i < formula.length() - 1; i++)
	{
		if (isdigit(formula[i])) {
			if (isdigit(formula[i + 1])) throw exception("Can't be 2 digits in a row");
		}
		else {
			if (validSymbols.find(formula[i]) == string::npos) throw exception("Invalid symbol found");
			if (!isdigit(formula[i + 1])) throw exception("Can't be 2 operations in a row");
		}
	}
	if (!isdigit(formula.back())) throw exception("Last symbol must be digit");

	root = new Node();
	recursionAdd(root, formula);
}

void recursionPrint(Node* current)
{
	cout << current->value;
	if (current->left) recursionPrint(current->left);
	if (current->right) recursionPrint(current->right);
}

void BinaryTree::printPrefix()
{
	if (root) recursionPrint(root);
}

void recursionDestruct(Node* current)
{
	if (current->left) recursionDestruct(current->left);
	if (current->right) recursionDestruct(current->right);
	delete current;
}

BinaryTree::~BinaryTree()
{
	if (root) recursionDestruct(root);
}
