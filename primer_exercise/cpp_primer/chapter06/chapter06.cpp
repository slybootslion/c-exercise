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
	void test04(initializer_list<int> const& li) {
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

	/*
	 练习6.30:编译第200页的str_subrange函数，看看你的编译器是如何处理函数中的错误的。

		bool str_subrange(const string &str1,const string &str2){
			if(str1.size()==str2.size())
				return str1==str2;
			auto size=(str1.size()<str2.size())?str1.size():str2.size();
			for(decltype(size) i=0;i!=size;++i){
				if(str1[i]!=str2[i])
					return;// Non-void function 'str_subrange' should return a value
			}
			// Non-void function does not return a value in all control paths
		}
	 * */

	/*
	 练习 6.31:什么情况下返回的引用无效?什么情况下返回常量的引用无效?

	 当返回的是函数内部的局部变量的引用或常量引用时，是无效的。

	 函数返回的引用必须满足：引用的对象是一个在调用函数之前就存在的对象；如果引用的对象只是函数中的一个局部对象，
	 那么函数返回这个引用是无效的。同样，返回的常量的引用有效的条件是：引用的对象是一个在调用函数之前就存在的对象。
	 如果引用的对象只是函数中的一个局部对象，那么函数返回这个引用是无效的。
	 * */

	/*
	 练习6.32：下面的函数合法吗？如果合法，说明其功能；如果不合法，修改其中的错误并解释原因。

		int &get(int *array, int index) {return array[index]; }
		int main()
		{
			 int ia[10];
			 for( int i = 0; i != 10; ++i)
				get(ia, i) = i;
		}

	 	合法，该函数将数组ia的10个元素分别初始化为0-9
	 * */

	/*
	 练习6.33：编写一个递归函数，输出vector对象的内容。
	 * */
	void test633(const vector<int>& v, int i) {
		if (i < v.size()) {
			cout << v[i] << endl;
			test633(v, i + 1);
		}
	}

	void q6_33() {
		vector<int> v = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
		test633(v, 0);
	}

	/*
	 练习6.34：如果factorial函数的停止条件如下所示，将发生什么情况？
		if(val!=0)

	 输入负数会进入死循环
	 * */

	/*
	 练习6.35：在调用factorial函数时，为什么我们传入的值是val-1而非val--?
	 调用factorial函数执行过程如图6-3所示，递归函数需要从图中的最下面计算上去，如果将传入的值修改为val-- ,
	 假设实参val=5，那么程序将会一直执行factorial(val--)，因为val=5>1,而val--永远先使用val=5,相当于程序不断的执行factorial(5)。

	 我们还可以假设把传入的值改为--val,那么输出facotrial(5)的结果不再是正确的120，而是24，
	 因为--val先执行val=val-1=4，当程序从递归中返回到最顶层时，此时要相乘val=4而不是5,相当于factorial(4)*4。
	 * */

	/*
	 练习6.36：编写一个函数的声明，使其返回数组的引用并且该数组包含10个string对象。
	 不要使用尾置返回类型、decltype或者类型别名。

	 答：string (&(arrStr(string (&arr)[10])))[10];
	 * */

	/*
	 练习6.37：为上一题的函数再写三个声明，一个使用类型别名，另一个使用尾置返回类型，最后一个使用decltype关键字。
	 你觉的哪种形式最好，为什么？

	 类型别名好，写法清楚。
	 * */
	using str_ten = string[10];

	str_ten& test637(str_ten& s); // 这个是声明

	auto test637_2(string(& s)[10]) -> string(&)[10]; // 尾置

	string arr[10] = {};

	decltype(arr)& test637_3(string (& s)[10]); // decltype

	void q6_37() {
		str_ten s = { "a", "a", "a", "a", "a", "a", "a", "a", "a", "a" };
		test637(s);
		for (const auto& c: s)
			cout << c << ", ";
		cout << endl;
	}

	str_ten& test637(str_ten& s) {
		for (auto& c: s) {
			c += "b";
		}
		return s;
	}

	/*
	 练习6.38：修改arrPtr函数，使其返回数组的引用。
	 * */
	int odd[] = { 1, 3, 5, 7, 9 };
	int even[] = { 0, 2, 4, 6, 8 };

	decltype(odd)& arrPtr(int i) {
		return i % 2 ? odd : even;
	}

	void q6_38() {
		for (auto& i: arrPtr(1)) {
			cout << i << ", ";
		}
		cout << endl;
		for (auto& i: arrPtr(2)) {
			cout << i << ", ";
		}
		cout << endl;
	}

	/*
	 练习6.39：说明在下面的每组声明中第二条语句是何含义。如果有非法的声明，请指出来。
		(a) int calc(int, int);
			int calc(const int,const int); // 非法，无法重载 顶层const形参和没有顶层const形参是一样的
		(b)int get();
		   double get(); // 不合法，两个函数只是返回类型不同，实质上两个函数重定义了。
		(c)int *reset(int *);
		   double *reset(double *);// 合法
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
//		q6_27();
//		q6_33();
//		q6_37();
		q6_38();

	}
}
