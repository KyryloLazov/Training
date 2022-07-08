#include "Node.h"

Node::Node(int value)
{
	this->value = value;
	parent = nullptr;
	left = nullptr;
	right = nullptr;
}

Node::Node(int value, Node* parent)
{
	this->value = value;
	this->parent = parent;
	left = nullptr;
	right = nullptr;
}

Node* Node::anyChild()
{
	if (left) return left;
	else return right;
}

int Node::childCount() const
{
	int count = 0;
	if (right) count++;
	if (left) count++;
	return count;
}
