#include"Functions.h"

void Createfile(const string& file_name) {
	Train a(13, "Kyiv", "10.06", "12:20");
	Train b(15, "Lviv", "15.07", "17:30");
	Train c(25, "Kharkiv", "25.05", "11:00");

	Train* arr = new Train[3];
	arr[0] = a;
	arr[1] = b;
	arr[2] = c;

	ofstream write_file(file_name, ios::binary);
	for (int i = 0; i < 3; i++) {
		write_file.write((char*)&arr[i], sizeof(Train));
	}
	write_file.close();
}

Train* ReadFile(const string& file_name) {
	ifstream read(file_name, ios::binary);
	Train* arr = new Train[3];
	for (int i = 0; i < 3; i++) {
		read.read((char*)&arr[i], sizeof(Train));
	}
	read.close();
	return arr;
}