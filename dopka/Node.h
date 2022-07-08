#pragma once
#include"Train.h"

struct Node {
	Train data;
	Node* next;

	Node();
	Node(Train value);
};
