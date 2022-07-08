#include "Node.h"

Node::Node(char value)
{
	this->value = value;
	parent = nullptr;
	left = nullptr;
	right = nullptr;
}

Node::Node(char value, Node* parent)
{
	this->value = value;
	this->parent = parent;
	left = nullptr;
	right = nullptr;
}

Node::Node(Node* parent)
{
	this->value = 0;
	this->parent = parent;
	left = nullptr;
	right = nullptr;
}

Node::Node()
{
	this->value = 0;
	parent = nullptr;
	left = nullptr;
	right = nullptr;
}
