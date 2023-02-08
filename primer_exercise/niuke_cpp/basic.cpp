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

		int max = a > b ? a > c ? a : c : b > c ? b : c;
		cout << max << endl;
	}

	// CPP8 计算商品打折结算金额
	void cpp8() {
		double price;
		cin >> price;

		double cost = 0.0;

		if (price >= 5000) {
			cost = price * 0.6;
		} else if (price >= 2000) {
			cost = price * 0.7;
		} else if (price >= 500) {
			cost = price * 0.8;
		} else if (price >= 100) {
			cost = price * 0.9;
		}

		cout << setiosflags(ios::fixed) << setprecision(1) << cost << endl;
	}

	// CPP9 判断身材状态
	void cpp9() {
		double weight;
		double height;

		cin >> weight;
		cin >> height;

		// write your code here......
		double bmi = weight / (height * height);
		if (bmi < 18.5)
			cout << "偏瘦";
		if (bmi >= 18.5 && bmi < 20.9)
			cout << "苗条";
		if (bmi >= 20.9 && bmi < 24.9)
			cout << "适中";
		if (bmi > 24.9)
			cout << "偏胖";
	}

	// CPP10 判断成绩等级
	void cpp10() {
		int score;
		cin >> score;
		if (score < 0 || score > 100) {
			cout << "成绩不合法";
		} else if (score >= 90) {
			cout << "优秀";
		} else if (score >= 80) {
			cout << "良";
		} else if (score >= 70) {
			cout << "中";
		} else if (score >= 60) {
			cout << "及格";
		} else {
			cout << "差";
		}
	}

	//  CPP11 判断季节
	void cpp11() {
		int month;
		cin >> month;
		if (month < 1 || month > 12) //优先判断是否合法月份
			cout << "不合法" << endl;
		else {
			switch (month) { //根据月份判断
			case 3 ... 5: //连续的值
				cout << "春季" << endl;
				break;
			case 6 ... 8:
				cout << "夏季" << endl;
				break;
			case 9 ... 11:
				cout << "秋季" << endl;
				break;
			default:
				cout << "冬季" << endl;
			}
		}
	}

	// CPP12 求 1 - n 之间偶数的和
	void cpp12() {
		int n;
		cin >> n;
		int sum = 0;
		while (n) {
			if (!(n % 2))
				sum += n;
			n--;
		}
		cout << sum << endl;
	}

	// CPP13 计算一个数的阶乘
	void cpp13() {
		int n;
		cin >> n;
		long long factorial = 1;
		n = n + 1;
		while (n--)
			n > 0 && (factorial *= n);
		cout << factorial << endl;
	}

	// CPP14 输出水仙花数
	void cpp14() {
		for (int i = 100; i < 999; i++) {
			int a = i % 10, b = (i / 10) % 10, c = i / 100;
			if (a * a * a + b * b * b + c * c * c == i)
				cout << i << endl;
		}
	}

	// CPP15 打印乘法表
	void cpp15() {
		int n;
		cin >> n;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= i; j++) {
				string b = "   ";
				if (j == i) b = "";
				cout << j << " * " << i << " = " << i * j << "    ";
			}
			cout << endl;
		}
	}

	// CPP16 规律数列求和
	void cpp16() {
		long long sum = 0, num = 0;
		for (int i = 1; i <= 10; i++) {
			num = num * 10 + 9;
			sum += num;
		}
		cout << sum << endl;
	}

	// CPP17 计算小球走过的路程和反弹高度
	void cpp17() {
		double h;
		int n;
		cin >> h;
		cin >> n;
		double res;
		for (int i = 0; i < n; i++) {
			if (i == 0)
				res = h;
			else
				res = res + 2 * h;
			h /= 2;
		}
		cout << fixed << setprecision(1) << res << " " << h << endl;
	}

	// CPP18 判断一个数是不是质数
	void cpp18() {
		bool check = true;
		int n;
		cin >> n;
		if (n == 2) {
			cout << "是质数";
			return;
		}
		for (int i = 2; i < n; i++) {
			if (!(n % i)) {
				check = false;
				break;
			}
		}
		check ? cout << "是质数" : cout << "不是质数";
	}

	void main() {
//		cpp1();
//		cpp2();
//		cpp3();
//		cpp4();
//		cpp5();
//		cpp6();
//		cpp7();
//		cpp8();
//		cpp9();
//		cpp10();
//		cpp11();
//		cpp12();
//		cpp13();
//		cpp14();
//		cpp15();
//		cpp16();
//		cpp17();
//		cpp18();

	}
}
