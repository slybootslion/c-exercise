#include "day02.h"

double power(double x, int n) {
	double val = 1;
	while (n) {
		val *= x;
		n--;
	}
	return val;
}

void day02::day02_1() {
	cout << "enter two number: ";
	double x, sum;
	int n;
	cin >> x >> n;
	sum = power(x, n);
	cout << sum << endl;
}


