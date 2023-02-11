#include "function.h"

namespace function
{
// CPP30 数组元素处理
	void func(int* p, int n) {
		int x = 0;
		for (int i = 0; i < n; i++) {
			if (p[i] != 0) {
				int temp = p[i];
				p[i] = p[x];
				p[x] = temp;
				x++;
			}
		}
	}

	void cpp30() {
		int arr[6] = { 0 };
		for (int i = 0; i < 6; i++) {
			cin >> arr[i];
		}

		func(arr, 6);

		for (int i = 0; i < 6; i++) {
			if (i == 5) {
				cout << arr[i] << endl;
			} else {
				cout << arr[i] << " ";
			}
		}
	}

	// CPP31 比较字符串大小
	int mystrcmp(const char* src, const char* dst) {
		char* p1 = (char*)src, * p2 = (char*)dst;
		while (*p1 != '\0' || *p2 != '\0') {
			if (*p1 < *p2) return -1;
			else if (*p1 > *p2) return 1;
			p1++;
			p2++;
		}
		return 0;
	}

	void cpp31() {
		char s1[100] = { 0 };
		char s2[100] = { 0 };
		cin.getline(s1, sizeof(s1));
		cin.getline(s2, sizeof(s2));
		int ret = mystrcmp(s1, s2);
		cout << ret << endl;
	}

	// CPP32 编写函数实现两数交换（指针方式）
	void cpp32() {
		int m, n;
		cin >> m;
		cin >> n;
		int* p = &m, * q = &n;
		int t = *p;
		*p = *q;
		*q = t;
		cout << m << " " << n << endl;
	}

	// CPP33 统计字符串中子串出现的次数
	void cpp33() {
		char str[100] = { 0 };
		char substr[100] = { 0 };
		cin.getline(str, sizeof(str));
		cin.getline(substr, sizeof(substr));
		int count = 0;
		for (int i = 0; str[i] != '\0'; i++) {
			bool flag = true;
			for (int j = 0; substr[j] != '\0'; j++) {
				if (str[i + j] != '\0' && str[i + j] == substr[j])
					continue;
				else {
					flag = false;
					break;
				}
			}
			if (flag) count++;
		}
		cout << count << endl;
	}

	// CPP34 使用字符函数统计字符串中各类型字符的个数
	void cpp34() {
		string str;
		getline(cin, str);
		int whitespace = 0;
		int digits = 0;
		int chars = 0;
		int others = 0;
		for (char c: str) {
			if (isalnum(c)) {
				if (isdigit(c)) digits++;
				else chars++;
			} else if (isspace(c)) whitespace++;
			else others++;
		}
		cout << "chars : " << chars
			 << " whitespace : " << whitespace
			 << " digits : " << digits
			 << " others : " << others << endl;
	}

	// CPP35 函数实现计算一个数的阶乘
	long long factorial(int n) {
		if (n == 0)
			return 1;
		return n * factorial(n - 1);
	}

	void cpp35() {
		int n;
		cin >> n;
		cout << factorial(n) << endl;
	}

	// CPP36 不死神兔问题
	int getSum(int n) {
		if (n == 2 || n == 1)
			return 1;
		return getSum(n - 1) + getSum(n - 2);
	}

	void cpp36() {
		int n;
		cin >> n;
		cout << getSum(n) << endl;
	}

	// CPP37 编写函数实现两数交换（引用方式）
	void myswap(int& a, int& b) {
		int t = a;
		a = b;
		b = t;
	}

	void cpp37() {
		int m, n;
		cin >> m;
		cin >> n;
		myswap(m, n);
		cout << m << " " << n << endl;
	}

	// CPP58 编写函数实现字符串翻转（引用方式）
	void reverse_string(string& s) {
		unsigned long len = s.size();
		for (int i = 0; i < len / 2; i++) {
			char temp = s[i];
			s[i] = s[len - i - 1];
			s[len - i - 1] = temp;
		}
	}

	void cpp38() {
		string s;
		getline(cin, s);
		reverse_string(s);
		cout << s;
	}

	void main() {
//		cpp30();
//		cpp31();
//		cpp32();
//		cpp33();
//		cpp34();
//		cpp35();
//		cpp36();
//		cpp37();
		cpp38();

	}
}
