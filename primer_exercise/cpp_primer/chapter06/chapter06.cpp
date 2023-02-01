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

	 当实参到形参的拷贝过大时，或者需要在函数内改变实参时，需要使用引用。
	 当不希望函数内部改变传递进来的实参，就不应该使用引用。
	 * */

	/*
	 练习 6.15:说明find_char函数中的三个形参为什么是现在的类型，特别说明为什么s是常量引用而occurs是普通引用?
	 为什么s 和occurs 是引用类型而c不是?
	 如果令s是普通引用会发生什么情况?
	 如果令occurs是常量引用会发生什么情况?

	 find_char这个函数需要遍历string类型的s,并不会改变s的值，从而是常量引用(使用引用是从效率出发,使用常量是从需求出发)
	 occurs这个变量在函数内部会发生改变，并且需要改变传进来的实参的值，从而是普通引用
	 c选择非引用，参数不是大数据类型拷贝，性能可以接受。
	 如果s是普通引用，那么在函数内部就会有改变s的值的可能性，也会给调用这个函数的人一种假象，这个函数是会改变s的值的
	 如果occurs是常量引用，编译器会报错(在++occurs这一行)
	 * */

	/*
	 练习6.16:下面的这个函数虽然合法，但是不算特别有用。指出它的局限性并设法改善
		bool is_empty(string& s) { return s.empty(); }

	 说明：若形参申明成非常量引用，则该函数不能接受const对象、字面值的实参，并且要在一个
      形参为const引用的函数内调用本函数，会导致编译错误。
      而且非常量引用的形参会给调用者一种误导，以为函数内部会更改实参的值
      bool is_empty(const string& s) { return s.empty(); }
	 * */

	/*
	 练习6.17:编写一个函数，判断 string 对象中是否含有大写字母。
	 编写另一个函数把string对象全都改成小写形式。
	 在这两个函数中你使用的形参类型相同吗?为什么?
	 * */
	bool is_upper_case(const string& s) {
		for (const auto c: s)
			if (isupper(c)) return true;
		return false;
	}

	void string_to_lower_case(string& s) {
		for (char& c: s)
			if (c >= 'A' && c <= 'Z')
				c = (char)tolower(c);
	}

	void q6_17() {
		const bool res = is_upper_case("Abc");
		string r = res ? "true" : "false";
		cout << "is upper case: " << r << endl;
		// 不需要改变实参，所以这里选择const引用

		string l{ "ABc" };
		string_to_lower_case(l);
		cout << "lower case: " << l << endl;
		// 需要修改实参，所以选择普通引用
	}

	/*
	 练习 6.18:为下面的函数编写函数声明，从给定的名字中推测函数具备的功能。
	 (a)名为 compare 的函数，返回布尔值，两个参数都是 matrix 类的引用。
	 (b)名为 change_val的函数，返回 vector<int>的迭代器，有两个参数:一个是int，另一个是 vector<int>的迭代器。

	 bool compare(matrix &a, matrix &b);
	 vector<int>::iterator change_val(int a, vector<int>::iterator);
	 * */

	/*
	 练习6.19:假定有如下声明，判断哪个调用合法、哪个调用不合法。对于不合法的函数调用，说明原因。

	 double calc(double);
	 int count(const string &, char);
	 int sum(vector<int>::iterator, vector<int>::iterator, int);
	 vector<int> vec(10);
	 (a) calc(23.4, 55.1); //不合法，参数数量不对
	 (b) count("abcda", 'a'); // 对
	 (c) calc(66); // 对
	 (d) sum(vec.begin(), vec.end(), 3.8); // 合法，但精度丢失
	 * */

	/*
	 练习 6.20:引用形参什么时候应该是常量引用?
	 如果形参应该是常量引用，而我们将其设为了普通引用，会发生什么情况?

	 当不需要在函数内部修改实参的值时，就需要将形参声明成常量引用，而不是非常量引用。
	 将形参声明成引用，既可以节省存储空间，又可以减少构造和析构对象的时间。
	 要是形参应该是常量引用，但却声明成普通引用，则函数内部可能会改变实参的值导致程序运行不
	 符合预期，并且这样的函数的应用场景会受到一定限制(实参就不能为常量对象了)

	 把函数不会改变的形参定义成普通的引用是一种比较常见的错误，这么做带给函数的调用者一种误导，即函数可以修改它的实参的值。
	 此外，使用引用而非常量引用也会极大地限制函数所能接受的实参类型（不能把const对象、字面值或者需要类型转换的对象传递给普通的引用形参。）
	 * */

	/*
	 练习6.21:编写一个函数，令其接受两个参数:一个是 int 型的数，另一个是 int 指针。函数比较 int 的值和指针所指的值，返回较大的那个。
	 在该函数中指针的类型应该是什么?
	 * */
	int test03(int a, const int* b) { // const int* 类型
		return a > *b ? a : *b;
	}

	void q6_21() {
		int b = 100;
		int res = test03(99, &b);
		cout << "bigger num is: " << res << endl;
	}

	/*
	 练习6.22:编写一个函数，令其交换两个int指针。
	 * */
	void change_int_pointer(int*& a, int*& b) {
		int* temp = a;
		a = b;
		b = temp;
	}

	void q6_22() {
		int a = 10, b = 11;
		int* p1 = &a, * p2 = &b;
		cout << "a = " << p1 << " b = " << p2 << endl; // a = 0x7fff18855e90 b = 0x7fff18855e94
		change_int_pointer(p1, p2);
		cout << "a = " << p1 << " b = " << p2 << endl; // a = 0x7fff18855e94 b = 0x7fff18855e90
	}

	/*
	 练习 6.23:参考本节介绍的几个print函数，根据理解编写你自己的版本。依次调用每个函数使其输入下面定义的i和j:
	 int i=0，j[2]={0，1};
	 * */

	void print_(int i) {
		cout << i << endl;
	}

	void print_(const int (& j)[2]) {
		for (auto i: j)
			print_(i);
	}

	void print_(const int* begin, const int* end) {
		while (begin != end) {
			cout << *begin++ << endl;
		}
	}

	void q6_23() {
		int i = 0, j[2] = { 0, 1 };
		print_(i);
		print_(j);
		print_(begin(j), end(j));
	}

	/*
	 练习 6.24:描述下面这个函数的行为。如果代码中存在问题，请指出并改正。
		void print(const int ia[10])
		{
			for (size_t i = 0; i != 10; ++i)
				cout << ia[i] << endl;
		}

	 函数的形参若是数组，则调用时，实参会自动转换成指向数组首元素的指针，所以数组的维度是无法隐式的通过数组名传递过来的，必须显示的通过形参传递
	 void print(const int* ia, size_T len) {
	 	for(size_t i = 0; i != len; ++i)
	 		cout << ia[i] << endl;
	 }
	 * */

	/*
	 练习6.27:编写一个函数，它的参数是initializer_list<int>类型的对象，函数的功能是计算列表中所有元素的和。
	 * */
	void test04(initializer_list<int> const &li) {
		int s = 0;
		for (auto item: li)
			s += item;
		cout << "sum is: " << s << endl;
	}

	void q6_27() {
		test04({ 1, 2, 3, 4, 5, 6 });
	}

	/*
	练习 6.28: 在error_msg函数的第二个版本中包含ErrCode类型的参数，其中循环内的elem是什么类型？
		void error_msg(ErrCode e, initializer_list<string> li) {
			cout << e.msg() << ": ";
			for (const auto& elem: li)
				cout << elem << " ";
			cout << endl;
		}

	 const string& 类型
	 * */

	/*
	 练习6.29:在范围 for 循环中使用 initializer_list 对象时，应该将循环控制变量声明成引用类型吗?为什么?

	 因为initializer_list对象中的元素是常量值，要是将范围for循环中的循环控制变量声明成引用类型，并不能带来什么方便(因为并不能
	 通过该引用改变原有值)，但常量引用是一个非常好的选择。
	 * */


	void main() {
//		q6_3();
//		q6_5();
//		q6_6();
//		q6_7();
//		q6_10();
//		q6_11();
//		q6_12();
//		q6_17();
//		q6_21();
//		q6_22();
//		q6_23();
		q6_27();

	}
}
