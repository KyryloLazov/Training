#pragma once
#include<iostream>

using namespace std;

class Train {
	int number;
	string destination;
	string date;
	string time;
public:
	Train();
	Train(int, string, string, string);

	int getNumber();
	string getTime();
	void print();
};