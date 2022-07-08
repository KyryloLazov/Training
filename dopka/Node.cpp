#include"Node.h"

Node::Node() {
	data = Train();
	next = nullptr;
}

Node::Node(Train value) {
	data = value;
	next = nullptr;
}