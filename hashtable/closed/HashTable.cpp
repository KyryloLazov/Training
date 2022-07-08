#include "HashTable.h"
#include <iostream>

using namespace std;

short hashFunc(int value)
{
	return value % SHRT_MAX;
}

Hashtable::Hashtable()
{
	table = new int[SHRT_MAX];

	flag = new bool[SHRT_MAX];
	for (size_t i = 0; i < SHRT_MAX; i++)
	{
		flag[i] = false;
	}
}

void Hashtable::add(int value)
{
	short hash = hashFunc(value);
	while (flag[hash] and hash < SHRT_MAX) hash++;
	if (hash == SHRT_MAX) return;

	table[hash] = value;
	flag[hash] = true;
}

int* Hashtable::getValue(int value)
{
	short hash = hashFunc(value);

	while (flag[hash] and hash < SHRT_MAX) {
		if (table[hash] == value) break;
		else hash++;
	}
	if (hash == SHRT_MAX) return nullptr;
	else return &table[hash];
}

int Hashtable::getHash(short hash)
{
	return flag[hash] * table[hash];
}

void Hashtable::removeValue(int value)
{
	short hash = hashFunc(value);
	while (flag[hash] and hash < SHRT_MAX) {
		if (table[hash] == value) break;
		else hash++;
	}
	if (hash == SHRT_MAX) return;
	flag[hash] = false;
}

void Hashtable::removeHash(short hash)
{
	flag[hash] = false;
}

void Hashtable::print()
{
	for (size_t i = 0; i < SHRT_MAX; i++)
	{
		if (flag[i]) cout << table[i] << "\n";
	}
}

void Hashtable::generate(int size, int min, int max)
{
	for (size_t i = 0; i < size; i++)
	{
		add(rand() % (max - min + 1) + min);
	}
}

Hashtable::~Hashtable()
{
	delete[] table;
}
