#pragma once

short hashFunc(int value);

class Hashtable {
	int* table;
	bool* flag;
public:
	Hashtable();

	void add(int value);
	int* getValue(int value);
	int getHash(short hash);

	void removeValue(int value);
	void removeHash(short hash);

	void print();
	void generate(int size, int min, int max);

	~Hashtable();
};