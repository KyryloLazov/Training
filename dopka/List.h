#pragma once
#include"Node.h"

class List {
	int size;
	Node* head;
	Node* tail;
public:
	List();
	void Add(Train);

	friend List operator<<(List&, Train&);
	Train& operator[](int index);
	void print();
};