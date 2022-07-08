#include "Functions.h"
#include <random>
#include <iostream>

using namespace std;
void generateArray(int* arr, int size, int min, int max)
{
	for (size_t i = 0; i < size; i++)
	{
		arr[i] = rand() % (max - min + 1) + min;
	}
}

void printArray(int* arr, int size)
{
	for (size_t i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
	cout << "\n";
}
