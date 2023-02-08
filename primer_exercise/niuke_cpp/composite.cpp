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

	void main() {
		cpp19();

	}
}
