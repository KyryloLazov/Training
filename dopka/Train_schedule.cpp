#include"Train_schedule.h"

Train_schedule::Train_schedule() {
	arr = new Train[maxSize];
	size = 0;
}

int Train_schedule::getSize() {
	return size;
}

void Train_schedule::Add(Train value) {
	if (size == maxSize) {
		cout << "Schedule is full!" << endl;
	}
	else {
		arr[size] = value;
		size++;
	}
}

Train& Train_schedule::operator[](int index) {
	return arr[index];
}

void Train_schedule::print() {
	for (int i = 0; i < size; i++) {
		arr[i].print();
	}
}