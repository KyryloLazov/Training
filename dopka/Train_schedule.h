#pragma once
#include"Train.h"

class Train_schedule {
	const int maxSize = 30;
	Train* arr;
	int size;
public:
	Train_schedule();
	void Add(Train);

	int getSize();

	Train& operator[](int index);
	void print();
};
