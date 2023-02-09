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
				{22, 66, 44},
				{77, 33, 88},
				{25, 45, 65},
				{11, 66, 99}
		};
		int sum = 0;
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 3; j++) {
				sum += arr[i][j];
			}
		}
		cout << sum << endl;
	}

	void main() {
//		cpp19();
//		cpp20();
//		cpp21();
//		cpp22();
		cpp23();

	}
}
