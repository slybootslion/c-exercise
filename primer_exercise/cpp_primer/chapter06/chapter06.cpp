#include "chapter06.h"

namespace chapter06
{

	/*
	 练习 6.2:请指出下列函数哪个有错误，为什么?应该如何修改这些错误呢?
		(a) int f() {
			string s;
			// ...
			return s;
		}
	 	(b) f2(int i) { ... }
	 	(c) int calc(int v1, int v1) ... }
	 	(d) double square (double x) return x * x;

	 	a. 返回值类型和函数返回类型不匹配
	 	b. 函数没有写返回值类型
	 	c. 形参名有重复，函数体缺少一个左括号
	 	d. 函数体缺少一对括号
	 * */

	/*
	 练习 6.3:编写你自己的 fact 函数，上机检查是否正确。
	 * */
	auto fact(int val) {
		signed long long int res = val;
		while (--val)
			res *= val;
		return res;
	}

	void q6_3() {
		int val;
		cin >> val;
		cout << "fact: " << fact(val) << endl;
	}

	/*
	 练习 6.4:编写一个与用户交互的函数，要求用户输入一个数字，计算生成该数字的阶乘。在main函数中调用该函数。
	 同6.3
	*/

	/*
	 练习 6.5:编写一个函数输出其实参的绝对值
	*/
	auto q_abs(int a) {
		return abs(a);
	}

	void q6_5() {
		int val;
		cin >> val;
		signed int a = q_abs(val);
		cout << a << endl;
	}

	/*
	练习 6.6:说明形参、局部变量以及局部静态变量的区别。编写一个函数，同时用到这三种形式。

	 局部变量：在块内部定义的变量
	 形参：在函数形参列表内定义的局部变量
	 局部静态变量：在块内部定义的静态变量，具有全局生命周期
	 * */
	auto test01(int a) {
		int b = 1; // 局部变量
		static int res = 0; // 局部静态变量
		res += a + b;
		return res;
	}

	void q6_6() { // 形参
		cout << test01(1) << endl;
		cout << test01(1) << endl;
		cout << test01(1) << endl;
	}


	/*
	 练习 6.7:编写一个函数，当它第一次被调用时返回0，以后每次被调用返回值加1。
	 */
	int test02() {
		static int res = 0;
		return res++;
	}

	void q6_7() {
		int i = 5;
		while (i--)
			cout << test02() << endl;
	}

	/*
	 练习 6.10:编写一个函数，使用指针形参交换两个整数的值。
	 在代码中调用该函数并输出交换后的结果，以此验证函数的正确性。
	 * */
	void change_method(int* a, int* b) {
		int temp = *a;
		*a = *b;
		*b = temp;
	}

	void q6_10() {
		int a = 1, b = 2;
		cout << "a: " << a << " b: " << b << endl;
		change_method(&a, &b);
		cout << "a: " << a << " b: " << b << endl;
	}

	/*
	 练习 6.11:编写并验证你自己的reset函数，使其作用于引用类型的参数。
	 * */
	void reset(int& a) {
		a = 0;
	}

	void q6_11() {
		int a = 1;
		cout << "a = " << a << endl;
		reset(a);
		cout << "a = " << a << endl;
	}

	/*
	 练习 6.12:改写6.2.1 节中练习 6.10(第188 页)的程序，使用引用而非指针交换两个整数的值。
	 你觉得哪种方法更易于使用呢?为什么?

	 引用更易于使用，不知道为什么，写法简便。
	 * */
	void change_method_quote(int& a, int& b) {
		int t = a;
		a = b;
		b = t;
	}

	void q6_12() {
		int a = 1, b = 2;
		cout << "a: " << a << " b: " << b << endl;
		change_method_quote(a, b);
		cout << "a: " << a << " b: " << b << endl;
	}

	/*
	 练习 6.13:假设T是某种类型的名字，说明以下两个函数声明的区别:一个是void f(T)，另一个是void f(&T)。

	 &T是T的引用，非拷贝，修改会改变原本实参的值。T的参数会进行拷贝，不会改变原实参。
	 * */


	/*
	 练习 6.14:举一个形参应该是引用类型的例子，再举一个形参不能是引用类型的例子
	 练习 6.15:说明 find char 函数中的三个形参为什么是现在的类型，特别说明为什么s 是常量引用而occurs 是普通引用?为什么s 和occurs 是引用类型而c不是?如果令 s 是普通引用会发生什么情况?如果令 occurs 是常量引用会发生什么情况?
	 * */

	void main() {
//		q6_3();
//		q6_5();
//		q6_6();
//		q6_7();
//		q6_10();
//		q6_11();
		q6_12();

	}
}
