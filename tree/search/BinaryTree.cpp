#include  "BinaryTree.h"
#include <random>
#include <iostream>

using namespace std;

Binarytree::Binarytree()
{
	root = nullptr;
}

Node* findTrueParent(Node* current, int value)
{
	if (value >= current->value) {
		if (current->right) return findTrueParent(current->right, value);
		else return current;
	}
	else {
		if (current->left) return findTrueParent(current->left, value);
		else return current;
	}
}

void Binarytree::addNode(int value)
{
	if (!root) {
		root = new Node(value);
		return;
	}

	Node* trueParent = findTrueParent(root, value);
	if (value >= trueParent->value) {
		trueParent->right = new Node(value, trueParent);
	}
	else {
		trueParent->left = new Node(value, trueParent);
	}
}

Node** getChildPtr(Node* parent, Node* child)
{
	if (!parent) return nullptr;
	if (parent->right == child) return &parent->right;
	else if (parent->left == child) return &parent->left;
	else return nullptr;
}

void Binarytree::removeNode(int value)
{
	Node* findedNode = findNode(value);
	if (!findedNode) return;

	Node** childPtr;
	if (findedNode->childCount() == 0) {

		childPtr = getChildPtr(findedNode->parent, findedNode);
		if(childPtr) *childPtr = nullptr;

	}
	else if(findedNode->childCount() == 1) {

		childPtr = getChildPtr(findedNode->parent, findedNode);
		if (childPtr) {
			*childPtr = findedNode->anyChild();
			findedNode->anyChild()->parent = findedNode->parent;
		}

	}
	else {
		Node* baseNode = findedNode;

		findedNode = findedNode->left;
		while (findedNode->right) findedNode = findedNode->right;
		baseNode->value = findedNode->value;

		childPtr = getChildPtr(findedNode->parent, findedNode);
		if (childPtr) {
			*childPtr = findedNode->anyChild();
			if(findedNode->childCount()) findedNode->anyChild()->parent = findedNode->parent;
		}
	}

	if (findedNode == root) root = findedNode->anyChild();

	delete findedNode;
}

Node* recursionFind(Node* current, int value)
{
	if (value == current->value) return current;
	else if (value > current->value) {
		if (current->right) return recursionFind(current->right, value);
		else return nullptr;
	}
	else {
		if (current->left) return recursionFind(current->left, value);
		else return nullptr;
	}
}

Node* Binarytree::findNode(int value)
{
	if (root) return recursionFind(root, value);
	return nullptr;
}

void Binarytree::recursionPrint(Node* toPrint, int& counter) 
{
	cout << toPrint->value << " ";
	counter++;
	if (toPrint->left) recursionPrint(toPrint->left, counter);
	if (toPrint->right) recursionPrint(toPrint->right, counter);
}

int Binarytree::print()
{
	if (!root) return 0;
	int counter = 0;
	recursionPrint(root, counter);
	cout << "\n";
	return counter;
}

void Binarytree::generate(int size, int min, int max)
{
	for (size_t i = 0; i < size; i++)
	{
		addNode(rand() % (max - min + 1) + min);
	}
}

void recursionDestructor(Node* toDestruct) {
	if (toDestruct->right) recursionDestructor(toDestruct->right);
	if (toDestruct->left) recursionDestructor(toDestruct->left);
	delete toDestruct;
}

Binarytree::~Binarytree()
{
	if (root) recursionDestructor(root);
}
