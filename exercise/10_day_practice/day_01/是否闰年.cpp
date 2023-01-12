#include "day01.h"

void day01::day01_2() {
	int year;
	cout << "enter the year: ";
	cin >> year;
	if (year <= 0) {
		perror("enter year error.");
		return;
	}
	bool isLeapYear = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
	if (isLeapYear)
		cout << year << " is leap year." << endl;
	else
		cout << year << "is not leap year." << endl;

}
