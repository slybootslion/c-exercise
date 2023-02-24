#include "point.h"

namespace point
{
	// CC1 获取字符串长度
	void c11() {
		char str[100] = { 0 };
		cin.getline(str, sizeof(str));
		char* p = str;
		while (*p++ != '\0');
		cout << p - str - 1;
	}

	// CC2 复制部分字符串
	void cc2() {
		char str[30] = { 0 };
		cin.getline(str, sizeof(str));
		int m;
		cin >> m;

		char cp[30] = { 0 };
		char* p = str + m - 1, * p2 = cp;
		while (*p != '\0') {
			*p2 = *p;
			p++;
			p2++;
		}
		cout << cp;
	}

	// CC3 编写函数实现两数交换（指针方式）
	void cc3() {
		int m, n;
		cin >> m;
		cin >> n;

		int* p = &m, * q = &n;
		int temp = *p;
		*p = *q;
		*q = temp;
		cout << m << " " << n << endl;
	}

	// CC4 利用指针遍历数组
	void cc4() {
		int arr[6] = { 0 };
		int* ptr = arr;
		// 键盘随机输入 6 个整数，将这些数据保存到数组中，利用指针遍历数组中的元素并打印。
		int len = sizeof(arr) / sizeof(int);
		for (int i = 0; i < len; i++) {
			cin >> arr[i];
		}
		for (int i = 0; i < len; ++i) {
			cout << *ptr << " ";
			ptr++;
		}
	}

	// CC6 牛牛的排序
	void sort(int *a, int n) {
		if (n <= 1) return;
		for(int i = 0; i < n - 1; i++){
			for (int j = 0; j < n - 1; j++) {
				if (a[j] > a[j + 1])
					swap(a[j], a[j + 1]);
			}
		}
	}

	void cc6 () {
		int n;
		cin >> n;

		int m[n];
		for (int i = 0; i < n; i++)
			cin >> m[i];
		sort(m, n);
		for (int i = 0; i < n; i++)
			cout << m[i] << " ";
	}

	void main() {
//		c11();
//		cc2();
//		cc3();
//		cc4();
		cc6();

	}
}
