#include"Train.h"
#include"Train_schedule.h"
#include"List.h"
#include"Functions.h"

using namespace std;

int main() {
	Createfile("input.txt");
	Train* arr = new Train[3];
	arr = ReadFile("input.txt");

	Train_schedule schedule;
	for (int i = 0; i < 3; i++) {
		schedule.Add(arr[i]);
	}
	cout << "Input time interval(hour:min - hour:min): ";
	string interval;
	cin >> interval;

	List list;

	int k = interval.find("-");
	string min = interval.substr(0, k);
	string max = interval.substr(k + 1);
	int s = min.find(":");
	int min_hour = stoul(min.substr(0, s));
	int min_minute = stoul(min.substr(s + 1));

	
	int l = max.find(":");
	int max_hour = stoul(max.substr(0, l));
	int max_minute = stoul(max.substr(l + 1));
	
	for (int i = 0; i < 3; i++) {
		string time = schedule[i].getTime();
		int k = time.find(":");
		int hour = stoul(time.substr(0, k));
		int minute = stoul(time.substr(k + 1));

		if (hour > min_hour and hour < max_hour) {
			list << schedule[i];
		}
		else if (hour == min_hour and minute > min_minute) {
			list << schedule[i];
		}
		else if (hour == max_hour and minute < max_minute) {
			list << schedule[i];
		}
	}

	list.print();

}