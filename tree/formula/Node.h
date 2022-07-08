#pragma once

struct Node {
	char value;
	Node* parent;
	Node* left;
	Node* right;

	Node(char value);
	Node(char value, Node* parent);
	Node(Node* parent);
	Node();
};