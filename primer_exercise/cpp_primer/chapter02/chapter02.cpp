#include "chapter02.h"

namespace chapter02
{

	/*
	 练习 2.18：编写代码分别更改指针的值及指针所指向对象的值。
	 * */
	void q2_18() {
		int b = 10, c = 11;
		int* a = &b;
		cout << "a = " << a << endl;
		// 更改指针的值
		a = &c;
		cout << "a = " << a << endl;
		// 更改指针所指向的对象的值
		*a = 5;
		cout << "c = " << c << endl;
	}

	/*
	 练习 2.20：请叙述下面这段代码的作用
	int i = 42;
	int *p1 = &i;
	*p1 = *p1 * *p1;

	 更改i的值为 42 * 42。
	 * */

	/*
	 练习 2.21：请解释下述定义。在这些定义中有非法吗？如果有，为什么？
	 int i = 0;
	(a) double* dp = &i; 非法，指向的类型不同
	(b) int *ip = i; 非法，不能将int直接赋值给int*
	(c) int *p = &i; 合法
	 * */

	/*
	 练习 2.22：假设p是一个int型指针，请说明下述代码的含义
	if (p)    // p非空指针nullptr则执行代码块
	if (*p)   // p所指向的对象不为0则执行代码块
	* */

	/*
	练习 2.25：说明下列变量的类型和值。
	(a) int* ip,i, &r = i; // int类型的指针，int类型，int类型的引用
	(b) int i, *ip = 0; // int类型，int类型的指针 需在函数体外才成立
	(c) int* ip, ip2; // int类型的指针，int类型
	 * */

	/*
	 练习 2.41：使用你自己的Sales_data类重写1.5.1节(第20页)、1.5.2节(第21页)和1.6节(第22页)的练习。
	 眼下先把Sales_data类的定义和main函数放在同一个文件里。
	 * */
	struct Sales_data
	{
		string bookNo;
		unsigned units_sold;
		double revenue;
	};

	void q2_25() {
		Sales_data book1, book2;
		double price1, price2;
		cin >> book1.bookNo >> book1.units_sold >> price1;
		cin >> book2.bookNo >> book2.units_sold >> price2;
		book1.revenue = book1.units_sold * price1;
		book2.revenue = book2.units_sold * price2;

		if (book1.bookNo == book2.bookNo) {
			unsigned totalCnt = book1.units_sold + book2.units_sold;
			double totalRevenue = book1.revenue + book2.revenue;
			cout << book1.bookNo << " " << totalCnt << " " << totalRevenue << endl;
		} else {
			cerr << "data must refer to same isbn" << endl;
		}
	}

	void main() {
		q2_25();
	}
}
