#include"List.h"

List::List() {
	size = 0;
	head = nullptr;
	tail = nullptr;
}

void List::Add(Train value) {
	Node* newPtr = new Node(value);
	if (size == 0) {
		head = newPtr;
		tail = newPtr;
		size = 1;
	}
	else {
		tail->next = newPtr;
		tail = tail->next;
		size++;
	}
}

List operator<<(List& a, Train& b) {
	a.Add(b);
	return a;
}

Train& List::operator[](int index) {
	Node* ptr = head;
	for (int i = 0; i < index; i++) {
		ptr = ptr->next;
	}
	return ptr->data;
}

void List::print() {
	Node* ptr = head;
	while (ptr->next) {
		ptr->next->data.print();
		ptr = ptr->next;
	}
	ptr->data.print();
}