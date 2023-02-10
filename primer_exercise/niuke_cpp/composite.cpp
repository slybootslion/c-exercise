#include "composite.h"

namespace composite
{
	//	CPP19 获取数组最值
	void cpp19() {
		int arr[6] = { 0 };
		int len = sizeof(arr) / sizeof(int);

		for (int i = 0; i < len; i++) {
			cin >> arr[i];
		}

		int min = arr[0], max = arr[0];
		for (int num: arr) {
			min = num < min ? num : min;
			max = num > max ? num : max;
		}
		cout << min << " " << max;
	}

	// CPP20 数组元素反转
	void cpp20() {
		int arr[6] = { 0 };

		int len = sizeof(arr) / sizeof(int);

		for (int i = 0; i < len; i++) {
			cin >> arr[i];
		}

		cout << "[";
		for (int i = 0; i < len; i++) {
			if (i == len - 1) {
				cout << arr[i] << "]" << endl;
				break;
			}
			cout << arr[i] << ", ";
		}

		// write your code here......
		int p1 = 0, p2 = len - 1;
		while (p1 < p2) {
			int t = arr[p1];
			arr[p1] = arr[p2];
			arr[p2] = t;
			p1++;
			p2--;
		}


		cout << "[";
		for (int i = 0; i < len; i++) {
			if (i == len - 1) {
				cout << arr[i] << "]" << endl;
				break;
			}
			cout << arr[i] << ", ";
		}
	}

	// CPP21 C++冒泡排序
	void cpp21() {
		int arr[6] = { 0 };
		int len = sizeof(arr) / sizeof(int);
		for (int i = 0; i < len; i++)
			cin >> arr[i];
		for (int i = 0; i < len - 1; i++) {
			for (int j = i + 1; j < len; j++) {
				if (arr[i] > arr[j]) {
					int t = arr[i];
					arr[i] = arr[j];
					arr[j] = t;
				}
			}
		}
		for (int i = 0; i < len; i++)
			cout << arr[i] << " ";
	}

	// CPP22 C++选择排序
	void cpp22() {
		int arr[6] = { 0 };
		int len = sizeof(arr) / sizeof(int);
		for (int i = 0; i < len; i++)
			cin >> arr[i];
		for (int i = 0; i < len - 1; i++) {
			int min = i;
			for (int j = i + 1; j < len; j++) {
				if (arr[j] < arr[min])
					min = j;
			}
			swap(arr[i], arr[min]);
		}
		for (int i = 0; i < len; i++)
			cout << arr[i] << " ";
	}

	// CPP23 计算公司年销售额
	void cpp23() {
		int arr[4][3] = {
				{ 22, 66, 44 },
				{ 77, 33, 88 },
				{ 25, 45, 65 },
				{ 11, 66, 99 }
		};
		int sum = 0;
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 3; j++) {
				sum += arr[i][j];
			}
		}
		cout << sum << endl;
	}

	// CPP24 字符串拼接
	void cpp24() {
		string s1, s2;
		getline(cin, s1);
		getline(cin, s2);
		cout << s1 + s2 << endl;
	}

	// CPP56 字符的个数
	void cpp56() {
		string s;
		cin >> s;
		int a = 0, b = 0, c = 0;
		for (auto ch: s) {
			switch (ch) {
			case 'a':
				a++;
				break;
			case 'b':
				b++;
				break;
			case 'c':
				c++;
				break;
			default:
				break;
			}
		}
		cout << a << ' ' << b << ' ' << c;
	}

	// CPP25 结构体简单使用
	struct student
	{
		string name;
		unsigned age{};
		double height{};
	};

	void cpp25() {
		string name;
		unsigned age;
		double height;
		cin >> name >> age >> height;
		struct student s;
		s.name = name;
		s.age = age;
		s.height = height;
		cout << s.name << ' ' << s.age << ' ' << s.height;
	}

	// CPP26 利用指针遍历数组
	void cpp26() {
		int arr[6] = { 0 };
		int* ptr = arr;
		int len = sizeof(arr) / sizeof(int);
		for (int i = 0; i < len; i++)
			cin >> arr[i];
		while (ptr <= &arr[5]) {
			cout << *ptr << " ";
			ptr++;
		}
	}

	// CPP27 获取字符串长度
	void cpp27() {
		char str[100] = { 0 };
		cin.getline(str, sizeof(str));

		// write your code here......
		int c = 0;
		char* p = str;
		while (*p != '\0') {
			c++;
			p++;
		}
		cout << c;
	}

	// CPP28 复制部分字符串
	void cpp28() {
		char str[100] = { 0 };
		cin.getline(str, sizeof(str));
		int c = 0;
		char* p = str;
		while (*p != '\0') {
			c++;
			p++;
		}
		cout << c;
	}

	// CPP29 创建动态数组
	void cpp29() {
		int n;
		cin >> n;
		int arr[n];
		for (int i = 0; i < n; i++) {
			arr[i] = n + i;
		}
		for (int i: arr)
			cout << i << ' ';
	}

	// CPP57 创建二维动态数组
	void cpp57() {
		int n;
		cin >> n;
		int arr[n][n];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++)
				arr[i][j] = i + j;
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++)
				cout << arr[i][j] << ' ';
			cout << endl;
		}
	}

	void main() {
//		cpp19();
//		cpp20();
//		cpp21();
//		cpp22();
//		cpp23();
//		cpp24();
//		cpp56();
//		cpp25();
//		cpp26();
//		cpp27();
//		cpp28();
//		cpp29();
		cpp57();

	}
}
