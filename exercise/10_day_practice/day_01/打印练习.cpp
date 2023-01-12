#include "day01.h"

void day01::day01_1() {
	for (int i = 1; i <= 4; ++i) {
		for (int j = 1; j <= 30; ++j)
			cout << " ";
		for (int k = 1; k <= 8 - 2 * i; ++k)
			cout << " ";
		for (int f = 1; f <= 2 * i; ++f)
			cout << "*";
		cout << endl;
	}
	for (int i = 1; i <= 3; ++i) {
		for (int j = 1; j <= 30; j++)
			cout << " ";
		for (int f = 1; f <= 7 - 2 * i; f++)
			cout << "*";
		cout << endl;
	}
}
