#pragma once
#include <cmath>
#include "Node.h"

short hashFunc(int value);

class Hashtable {
	Node** table;
	
public:
	Hashtable();

	void add(int value);

	Node* getNode(int value);
	Node* operator[](short hash);

	void deleteHash(short hash);
	void deleteValue(int value);

	void generate(int size, int min, int max);
	void print();

	~Hashtable();
};