#include "day02.h"

int roll_dice() {
	int sum = 0;
	int dim1 = rand() % 6 + 1;
	int dim2 = rand() % 6 + 1;
	sum = dim1 + dim2;
	cout << "sum: " << dim1 << "+" << dim2 << "=" << sum << endl;
	return sum;
}

void day02::day02_2() {
	int flag;
	int t = (int)time(nullptr);
	cout << "time: " << t << endl;
	srand(t);
	int sum = roll_dice();
	int self_dim;
	switch (sum) {
	case 7:
	case 11:
		flag = 1;
		break;
	case 2:
	case 3:
	case 12:
		flag = 2;
		break;
	default:
		flag = 0;
		self_dim = sum;
		break;
	}
	while (flag == 0) {
		sum = roll_dice();
		if (sum == self_dim) flag = 1;
		else if (sum == 7) flag = 2;
	}
	if (flag == 1) cout << "player win" << endl;
	else cout << "player loses" << endl;
}
