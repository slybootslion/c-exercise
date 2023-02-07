#include "basic.h"


namespace basic
{
	// CPP1 定义变量
	void cpp1() {
		char c = 'a';
		int i = 1;
		long int l = 1;
		double d = 0.0;

		cout << sizeof(c) << endl;
		cout << sizeof(i) << endl;
		cout << sizeof(l) << endl;
		cout << sizeof(d) << endl;
	}

	// CPP2 实现四舍五入
	void cpp2() {
		double d;
		while (cin >> d) {
			int num = d;
			if (d - num >= 0.5) num++;
			if (d - num < -0.5) num--;
			cout << num << endl;
		}
	}

	// CPP3 两数求和
	void cpp3() {
		int a, b;
		cin >> a >> b;
		if (a >= -1000 && a <= 1000 && b >= -1000 && b <= 1000) // 牛客提交时不用做判断，这里只是为了严谨，下同
			cout << a + b << endl;
	}

	// CPP4 获取两数中的较大值
	void cpp4() {
		int a, b;
		cin >> a >> b;
		b = a > b ? a : b;
		cout << b << endl;
	}

	// CPP5 简单运算
	void cpp5() {
		int a, b;
		cin >> a >> b;
		if (a >= 1 && a <= 9999 && b >= 1 && b <= 9999) {
			if (b > a) {
				int temp = b;
				b = a;
				a = temp;
			}
			cout << a + b << " " << a - b << " " << a * b << " " << a / b << " " << a % b << endl;
		}
	}

	// CPP6 交换两个变量的值
	void cpp6() {
		int a = 0;
		int b = 0;
		cin >> a;
		cin >> b;

		//write your code here.......
		swap(a, b); // 标准库
		cout << a << " " << b << endl;
	}

	// CPP7 获取三个数中的最大值（三元表达式实现）
	void cpp7() {
		int a, b, c;
		cin >> a;
		cin >> b;
		cin >> c;

		int max = a > b ? a > c ? a : c: b > c ? b : c;
		cout << max << endl;
	}

	void main() {
//		cpp1();
//		cpp2();
//		cpp3();
//		cpp4();
//		cpp5();
//		cpp6();
		cpp7();

	}
}
