#include <map>
#include "chapter01.h"
#include "Sales_item.h"

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

	/*
	 练习1.20：在网站http://www.informit.com/title/0321714113上，第一章的代码目录中包含了头文件Sales_item.h。
	 将它拷贝到你自己的工作目录中。用它编写一个程序，读取一组书籍销售记录，将每条记录打印到标准输出上。
	 * */
	void q1_20() {
		const static int MAX_LOOP_TIMES = 2;
		Sales_item item[MAX_LOOP_TIMES];
		for (int i = 0; i < MAX_LOOP_TIMES; ++i)
			cin >> item[i];
		for (int i = 0; i < MAX_LOOP_TIMES; ++i)
			cout << item[i] << endl;
	}

	/*
	练习 1.23：编写程序，读取多条销售记录，并统计每个ISBN(每本书)有几条销售记录。
	 * */
	void q1_23() {
		map<string, int> count_map;
		int is_loop = 0;
		do {
			cout << "Enter 1 to enter item info or enter 0 print and quit:";
			cin >> is_loop;
			if (is_loop != 0) {
				Sales_item item;
				cout << "Enter the book info: (tip:isbn sale_count sale_price):";
				cin >> item;

				auto map_it = count_map.begin();
				for (map_it; map_it != count_map.end(); ++map_it) {
					if (map_it->first == item.isbn()) {
						map_it->second++;
						break;
					}
				}

				if (map_it == count_map.end())
					count_map[item.isbn()] = 1;
			}
		} while (is_loop != 0);
	}

	void main() {
//		q1_9();
//		q1_10();
//		q1_11();
//		q1_16();
//		q1_20();
		q1_23();
	}
}
