#include "BinaryTree.h"
#include <iostream>

using namespace std;

BinaryTree::BinaryTree()
{
	root = nullptr;
}

BinaryTree::BinaryTree(int* arr, int size)
{
	for (size_t i = 0; i < size; i++)
	{
		addNode(arr[i]);
	}
}

bool checkFreeNode(Node* start)
{
	if (!start->left) return true;
	else if (!start->right) return true;
	else return false;
}

Node* getFreeNode(Node* thisNode, int aviableDepth)
{
	if (checkFreeNode(thisNode)) return thisNode;
	else if(aviableDepth) {
		Node* goLeft = getFreeNode(thisNode->left, aviableDepth - 1);
		if (goLeft) return goLeft;
		Node* goRight = getFreeNode(thisNode->right, aviableDepth - 1);
		if (goRight) return goRight;
	}
	return nullptr;
}

void BinaryTree::addNode(int value)
{
	if (!root) {
		root = new Node(value);
		return;
	}
	int depth = 0;
	Node* freeNode = nullptr;
	while (!freeNode) {
		freeNode = getFreeNode(root, depth);
		depth++;
	}
	if (!freeNode->left) {
		Node* newNode = new Node(value, freeNode);
		freeNode->left = newNode;
	}
	else {
		Node* newNode = new Node(value, freeNode);
		freeNode->right = newNode;
	}
}

Node* recursiveFind(Node* current, int value) 
{

	if (current->value == value) return current;

	if (current->left) {
		Node* left = recursiveFind(current->left, value);
		if (left) return left;
	}
	if (current->right) {
		Node* right = recursiveFind(current->right, value);
		if (right) return right;
	}

	return nullptr;
}

Node* BinaryTree::findNode(int value)
{
	if (!root) return nullptr;
	return recursiveFind(root, value);
}

Node* recursiveRight(Node* current)
{
	if (current->right) return recursiveRight(current->right);
	else if (current->left) return current->left;
	else return current;
}

void BinaryTree::deleteNode(int value)
{
	Node* findedNode = findNode(value);
	Node* emplacedNode;
	while (findedNode) {

		emplacedNode = recursiveRight(findedNode);
		findedNode->value = emplacedNode->value;
		if (!emplacedNode->parent) {
			delete emplacedNode;
			root = nullptr;
			return;
		}
		else if(emplacedNode->parent->right == emplacedNode) emplacedNode->parent->right = nullptr;
		else emplacedNode->parent->left = nullptr;
		delete emplacedNode;

		findedNode = findNode(value);
	}
}

void recursionPrintStraight(Node* current) 
{
	cout << current->value << " ";
	if (current->left) recursionPrintStraight(current->left);
	if (current->right) recursionPrintStraight(current->right);
}

void BinaryTree::printStraight()
{
	if (!root) return;
	recursionPrintStraight(root);
	cout << "\n";
}

void recursionPrintReverse(Node* current)
{
	if (current->left) recursionPrintReverse(current->left);
	if (current->right) recursionPrintReverse(current->right);
	cout << current->value << " ";
}

void BinaryTree::printReverse()
{
	if (!root) return;
	recursionPrintReverse(root);
	cout << "\n";
}

void recursionPrintSymmetrical(Node* current)
{
	if (current->left) recursionPrintSymmetrical(current->left);
	cout << current->value << " ";
	if (current->right) recursionPrintSymmetrical(current->right);
}

void BinaryTree::printSymmetrical()
{
	if (!root) return;
	recursionPrintSymmetrical(root);
	cout << "\n";
}

void recursionDestructor(Node* current) 
{
	if (current->left) recursionDestructor(current->left);
	if (current->right) recursionDestructor(current->right);
	delete current;
}

BinaryTree::~BinaryTree()
{
	if (!root) return;
	recursionDestructor(root);
}
