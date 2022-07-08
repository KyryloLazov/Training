#include "Hashtable.h"
#include <iostream>

using namespace std;


short hashFunc(int value) {
	return value % SHRT_MAX;
}

Hashtable::Hashtable()
{
	table = new Node*[SHRT_MAX];
	for (size_t i = 0; i < SHRT_MAX; i++)
	{
		table[i] = nullptr;
	}
}

Node* findEnd(Node* start) {
	while (start->next) start = start->next;
	return start;
}

void Hashtable::add(int value)
{
	short hash = hashFunc(value);
	Node* cell = table[hash];
	if (cell == nullptr) {
		table[hash] = new Node(value);
	}
	else {
		Node* parent = findEnd(cell);
		Node* newNode = new Node(value);
		parent->next = newNode;
	}
}

Node* Hashtable::getNode(int value)
{
	Node* result = table[hashFunc(value)];
	while (result->value != value) {
		if (!result->next) return nullptr;
		result = result->next;
	}
	return result;
}

Node* Hashtable::operator[](short hash)
{
	return table[hash];
}

void destructList(Node* head) {
	if (head == nullptr) return;
	Node* prev = head;
	while (head->next) {
		head = head->next;
		delete prev;
		prev = head;
	}
	delete head;
}

void Hashtable::deleteHash(short hash)
{
	destructList(table[hash]);
	table[hash] = nullptr;
}

void Hashtable::deleteValue(int value)
{
	Node* toDelete = table[hashFunc(value)];
	if (!toDelete) return;
	Node* prev = toDelete;
	Node* current = toDelete;
	while (current and current->next) {
		current = current->next;
		if (current->value == value) {
			prev->next = current->next;
			delete current;
			current = prev;
		}
		prev = current;
	}
	if (current and current->value == value) {
		if (current == toDelete) table[hashFunc(value)] = nullptr;
		delete current;
	}
}

void Hashtable::generate(int size, int min, int max)
{
	for (size_t i = 0; i < size; i++)
	{
		add(rand() % (max - min + 1) + min);
	}
}

void printList(Node* head) {
	while (head->next) {
		cout << head->value << "->";
		head = head->next;
	}
	cout << head->value <<endl;
}

void Hashtable::print()
{
	for (size_t i = 0; i < SHRT_MAX; i++)
	{
		if (table[i]) printList(table[i]);
	}
}



Hashtable::~Hashtable()
{
	for (size_t i = 0; i < SHRT_MAX; i++)
	{
		if (table[i]) printList(table[i]);
	}
}
