#include "chapter01.h"

namespace chapter01
{


	/*
	 练习1.9：编写程序，使用while循环将50到100的整数相加。
	 * */
	void q1_9() {
		int c = 50, count = 0;
		while (c <= 100) {
			count += c;
			c++;
		}
		cout << "Sum of 50 to 100 inclusive is " << count << endl;
	}

	/*
	 练习1.10：除了＋＋运算符将运算对象的值增加1之外，还有一个递减运算符（--）实现将值减
	 少1。编写程序，使用递减运算符在循环中按递减顺序打印出10到0之间的整数。
	 * */
	void q1_10() {
		int c = 11;
		while (c--)
			cout << c << endl;
	}

	/*
	 练习1.11：编写程序，提示用户输入两个整数，打印出这两个整数所指定的范围内的所有整数。
	 * */
	void q1_11() {
		int min, max;
		cout << "enter two numbers: " << endl;
		cin >> min >> max;
		if (min > max) {
			int t = min;
			min = max;
			max = t;
		}
		while (min <= max) {
			cout << min << ", ";
			min++;
		}
		cout << endl;
	}

	/*
	 练习1.16：编写程序，从cin读取一组数，输出其和。
	 * */
	void q1_16() {
		int sum = 0, value = 0;
		while (cin >> value)
			sum += value;
		cout << "sum is: " << sum << endl;
	}

	void main() {
//		q1_9();
//		q1_10();
//		q1_11();
//		q1_16();
	}
}
