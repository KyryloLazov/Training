#include"Train.h"

Train::Train() {
	number = 0;
	destination = "";
	date = "";
	time = "";
}

int Train::getNumber() {
	return number;
}

string Train::getTime() {
	return time;
}

Train::Train(int number, string destination, string date, string time) {
	this->number = number;
	this->destination = destination;
	this->date = date;
	this->time = time;
}

void Train::print() {
	cout << "train #" << number << " destination: " << destination << " date: " << date << " time:" << time<<endl;
}