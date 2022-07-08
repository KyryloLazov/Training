#pragma once

struct Node {
	int value;
	Node* parent;
	Node* left;
	Node* right;

	Node(int value);
	Node(int value, Node* parent);
};