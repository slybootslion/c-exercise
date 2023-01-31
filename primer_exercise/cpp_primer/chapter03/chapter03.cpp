#include "chapter03.h"

// 字符串字面量与string是不同的类型。

namespace chapter03
{
	/*
	 练习 3.2:编写一段程序从标准输入中一次读入一整行，然后修改该程序使其一次读入一个词。
 	* */
	void q3_2() {
		string str;
		while (getline(cin, str)) {
			cout << str << endl;
		}
		while (cin >> str) {
			cout << str << endl;
		}
	}

	/*
	 练习 3.3:请说明 string 类的输入运算符和 getline 函数分别是如何处理空白字符的。
	 string的输入运算符会自动忽略空白字符，而getline函数是按行获取字符的(不管行中是什么字符，都能存到string中)
	 * */

	/*
	 练习 3.4:编写一段程序读入两个字符串，比较其是否相等并输出结果。
	 如果不相等,输出较大的那个字符串。改写上述程序，比较输入的两个字符串是否等长，如果不等长，输出长度较大的那个字符串。
	 * */
	void q3_4() {
		string s1, s2;
		cin >> s1 >> s2;
		if (s1 == s2) cout << "equal strings" << endl;
		else if (s1 > s2) cout << s1 << endl;
		else cout << s2 << endl;

		auto size1 = s1.size(), size2 = s2.size();
		if (size1 == size2) cout << "equal size" << endl;
		else if (size1 > size2) cout << "long string is: " << s1 << endl;
		else cout << "long string is: " << s2 << endl;
	}

	/*
	练习 3.5:编写一段程序从标准输入中读入多个字符串并将它们连接在一起，输出连接成的大字符串。
	 然后修改上述程序，用空格把输入的多个字符串分隔开来。
	 * */

	void q3_5() {
		string str, res1, res2;
		cout << "input some words, no space." << endl;
		while (cin >> str) {
			res1 += str;
			res2 += str + " ";
			cout << "whether to continue?(y or n)" << endl;
			cin >> str;
			if (str == "n") break;
		}
		cout << res1 << endl;
		cout << res2 << endl;
	}

	/*
	 练习 3.6:编写一段程序，使用范围 for 语将字符串内的所有字符用X 代替。
	* */
	void q3_6() {
		string str = "thisisastring.";
		for (auto& c: str) {
			c = 'X';
		}
		cout << str << endl;
	}

	/*
	 练习 3.7:就上一题完成的程序而言，如果将循环控制变量的类型设为 char 将发生么?先估计一下结果，然后实际编程进行验证。
	 就本题而言，没有变化。
	 * */

	/*
	 练习 3.8:分别用 while 循环和传统的 for 循环重写第一题的程序，你觉得哪种形更好呢?为什么?
	 * */

	/*
	 练习3.9:下面的程序有何作用?它合法吗?如果不合法，为什么?
		string s;
		cout << s[0] << endl;

	 该程序是不合法的，下标的值只能在[0,s.size()-1]之间，显然现在s.size()为0，所以打印结果是未定义的
	 * */

	/*
	 练习3.10:编写一段程序，读入一个包含标点符号的字符串，将标点符号去除后输出符串剩余的部分。
	 * */
	void q3_10() {
		string s("this,is,a,string;.");
		string res;
		for (auto ch: s)
			if (!ispunct(ch)) res += ch;
		cout << res << endl;
	}

	/*
	 练习3.11:下面的范围 for 语句合法吗?如果合法，c的类型是什么?
		const string s = "Keep out!";
	 	for (auto &c : s) { * ... * }

	此处c是一个const char&，只可读变量不可赋值，所以当不改变c的值时，是合法的，否则不合法。
	 * */

	/*
	 练习3.12:下列 vector 对象的定义有不正确的吗?如果有，请指出来。对于正确的，描述其执行结果;对于不正确的，说明其错误的原因。
		(a)vector<vector<int>> ivec;
		(b)vector<string> svec = ivec;
		(c)vector<string> svec(10，"null");
	 	a. 正确，声明一个元素为vector<int>的vector对象。
	 	b. 错误，不能将vector<vector<int>>类型的对象赋值给vector<string>类型的对象
	 	c. 正确，vector<string>类型对象，包含10个"null"元素
	*/

	/*
	 练习 3.13:下列的 vector 对象各包含多少个元素?这些元素的值分别是多少?
		(a)vector<int> v1; (b)vector<int> v2(10);
		(c)vector<int> v3(10，42); (d)vector<int> v4{10};
		(e)vector<int> v5{10，42}; (f)vector<string> v6{10};
		(g)vector<string> v7{10，"hi"};
		a. 0
	 	b. 10，初始化为0
	 	c. 10，初始化为42
	 	d. 1，初始化值为10
	 	e. 2，包含元素10、42
	 	f. 10，初始化为空字符串
	 	g. 10，初始化为"hi"
	 * */

	/*
	 练习3.14:编写一段程序，用cin 读入一组整数并把它们存入一个 vector 对象。
	 * */
	void q3_14() {
		int i;
		vector<int> vi;
		while (cin >> i)
			vi.push_back(i);
		cout << "vector element are: ";
		for (auto item: vi)
			cout << item << " ";
		cout << endl;
	}

	/*
	 练习 3.15:改写上题的程序，不过这次读入的是字符串。
	 * */
	void q3_15() {
		string i;
		vector<string> vi;
		while (cin >> i)
			vi.push_back(i);
		cout << "vector element are: ";
		for (const auto& item: vi)
			cout << item << " ";
		cout << endl;
	}

	/*
	 练习 3.16:编写一段程序，把练习 3.13 中 vector 对象的容量和具体内容输出出来。检验你之前的回答
	 	是否正确，如果不对，回过头重新学习 3.3.1 节(第87 页)直到弄明白错在何处为止。
	*/
	// capacity是容器当前分配空间大小（最大元素数），size是当前容器真实占用的大小
	template<typename T>
	void print_vector(vector<T>& v) {
		cout << "capacity = " << v.capacity() << endl;
		if (v.capacity()) {
			cout << "element = ";
			for (auto& el: v)
				cout << el << ", ";
			cout << endl;
		} else cout << "element = " << 0 << endl;
	}

	void q3_16() {
		vector<int> v1;
		print_vector(v1);

		vector<int> v2(10);
		print_vector(v2);

		vector<int> v3(10, 42);
		print_vector(v3);

		vector<int> v4{ 10 };
		print_vector(v4);

		vector<int> v5{ 10, 42 };
		print_vector(v5);

		vector<string> v6{ 10 };
		print_vector(v6);

		vector<string> v7{ 10, "hi" };
		print_vector(v7);
	}

	/*
	 练习3.17:从cin读入一组词并把它们存入一个vector对象，然后设法把所有词都改写为大写形式。
	 	输出改变后的结果，每个词占一行。
	 * */
	void q3_17() {
		string str;
		vector<string> res;
		while (cin >> str)
			res.push_back(str);
		for (auto& s: res) {
			for (auto& c: s)
				c = (char)toupper(c);
		}
		for (auto& s: res)
			cout << "--> " << s << endl;
	}

	/*
	 练习 3.18:下面的程序合法吗?如果不合法，你准备如何修改?
		vector<int> ivec;
	 	ivec[0] =42;

	不合法，ivec未初始化元素。
	 修改为：vector<int> ivec{1}; ivec[0] = 42;
	 或者：vector<int> ivec; ivec.push_back(42);
	 * */

	/*
	 练习3.19:如果想定义一个含有10个元素的 vector 对象，所有元素的值都是42，请列举出三种不同的实现方法。
	 哪种方法更好呢?为什么?
	 第一种：vector<int> v(10, 42); 最好的方法，效率高，且易读。
	 第二种：vector<int> ivec{42,42,42,42,42,42,42,42,42,42};
	 第三种：vector<int> ivec;
			for(int i=0;i<10;++i){
				ivec.push_back(42);
			}
	 * */

	/*
	 练习3.20:读入一组整数并把它们存入一个 vector 对象，将每对相邻整数的和输出出来。
	 改写你的程序，这次要求先输出第1个和最后1个元素的和，接着输出第2个和倒数第2个元素的和，以此类推。
	 * */
	void q3_20() {
		int a;
		vector<int> res;
		while (cin >> a)
			res.push_back(a);
		// 相邻元素之和
		auto len = res.size();
		for (int i = 0; i < len; ++i) {
			if (i > 0)
				cout << res[i] + res[i - 1] << ", ";
		}
		cout << endl;

		// 首尾元素之和
		auto s = len % 2 == 0 ? len / 2 : len / 2 + 1;
		for (int i = 0; i < s; ++i) {
			if (&res[i] == &res[len - i - 1]) cout << res[i] << " "; // 地址相同的元素不应和自己相加
			else cout << res[i] + res[len - i - 1] << ", ";
		}
		cout << endl;
	}

	/*
	 练习 3.21:请使用迭代器重做3.3.3 节第94 页)的第一个练习。
	 * */
	template<typename T>
	void print_vector_it(vector<T>& v) {
		cout << "capacity = " << v.capacity() << endl;
		if (v.capacity()) {
			cout << "element = ";
			auto it = v.cbegin();
			for (; it != v.cend(); ++it)
				cout << *it << ", ";
			cout << endl;
		} else cout << "element = " << 0 << endl;
	}

	void q3_21() {
		vector<int> v1;
		print_vector_it(v1);

		vector<int> v2(10);
		print_vector_it(v2);

		vector<int> v3(10, 42);
		print_vector_it(v3);

		vector<int> v4{ 10 };
		print_vector_it(v4);

		vector<int> v5{ 10, 42 };
		print_vector_it(v5);

		vector<string> v6{ 10 };
		print_vector_it(v6);

		vector<string> v7{ 10, "hi" };
		print_vector_it(v7);
	}

	/*
	 练习3.22:修改之前那个输出 text 第一段的程序，首先把 text 的第一段全都改成大写形式，然后再输出它。
	 * */
	void q3_22() {
		vector<string> text;
		string line;
		while (getline(cin, line))
			text.push_back(line);
		for (auto it = text.begin(); it != text.end() && !it->empty(); ++it) {
			for (auto& c: *it)
				c = (char)toupper(c);
			cout << "-->" << *it << endl;
		}
	}

	/*
	 练习3.23:编写一段程序，创建一个含有10个整数的vector对象，然后使用选代器将所有元素的值都变成原来的两倍。
		输出 vector 对象的内容，检验程序是否正确。
	 * */
	void q2_23() {
		vector<int> v{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
		for (auto it = v.begin(); it != v.end(); ++it)
			*it = *it * 2;
		for (auto it = v.begin(); it != v.end(); ++it)
			cout << *it << ", ";
		cout << endl;
	}

	/*
	练习 3.24:请使用选代器重做3.3.3节(第94页)的最后一个练习。
	 * */
	void q3_24() {
		int a;
		vector<int> res;
		while (cin >> a)
			res.push_back(a);
		// 相邻元素和
		auto it = res.begin() + 1;
		for (; it != res.end(); ++it)
			cout << *it + *(it - 1) << ", ";
		cout << endl;
		// 首尾相加
		auto it_b = res.begin(), it_e = res.end() - 1; // it_m = it_b + (it_e - it_b) / 2
		while (it_b <= it_e) {
			if (it_b == it_e) cout << *it_b << " ";
			else cout << *it_b + *it_e << ", ";
			it_b++;
			it_e--;
		}
		cout << endl;
	}

	/*
	练习3.25:3.3.3 节(第93 页)划分分数段的程序是使用下标运算符实现的，请利用选代器改写该程序并实现完全相同的功能。
	 * */
	void q3_25() {
		vector<unsigned> scores(11, 0);
		unsigned grade;
		while (cin >> grade) {
			if (grade <= 100) {
				auto scores_it = scores.begin();
				++*(scores_it + grade / 10);
			}
		}
		for (auto it = scores.begin(); it < scores.end(); ++it)
			cout << *it << ", ";
		cout << endl;
	}

	/*
		练习 3.26:在100页的二分搜索程序中，为什么用的是mid = beg + (end - beg) / 2
		而非mid = (beg + end) /2;?

	 	迭代器不支持两个迭代器相加，但支持两个迭代器相减，所以可以选用mid=beg+(end-beg)/2，但不能选用mid=(beg+end)/2
	 * */

	/*
	 练习 3.27:假设 txt_size 是一个无参数的函数，它的返回值是int。请回答下列哪个定义是非法的?为什么?
		unsigned buf_size = 1024;
		(a)int ia[buf_size]; // 错误，不是常量
		(c)int ia[txt_size()]; // 错误，返回值不是const常量，返回值是constexpr时正确（constexpr int txt_size() {return 5;}）
		(b)int ia[4*7-14]; // 正确
		(d)char st[11] = "fundamental"; // 错误，没有留下\0的位置，这个数组的维度应该为12
	 * */

	/*
	练习 3.28:下列数组中元素的值是什么?
		string sa[10]; // 10个元素，空字符串
		int ia[10]; // 10个元素，0
		int main() {
			string sa2[10]; // 10个元素，空字符串
			int ia2[10]; // 10个元素，undefined（未定义）
		}
	 * */

	/*
	 练习 3.29:相比于vector 来说，数组有哪些缺点，请列举一些。
	 	1)数组的维度在编译时必须是已知的，从而大小不可变更，缺乏灵活性
	 	2)标准命名空间对vector的支持明显好于对数组的支持
	 * */

	/*
	 练习3.30:指出下面代码中的索引错误
		constexpr size_t array_size = 10;
		int ia[array_size];
		for (size_t ix = 1; ix <= array_size; ++ix)
			ia[ix] = ix;

	 当ix=array_size的时候，数组取值将越界。
	 * */

	/*
	 练习 3.31:编写一段程序，定义一个含有 10个int 的数组，令每个元素的值就是其下标值。
	 * */
	void q3_31() {
		int arr[10];
		for (int i = 0; i < 10; i++)
			arr[i] = i;
		for (int a: arr)
			cout << a << ", ";
		cout << endl;
	}

	/*
	 练习 3.32:将上一题刚刚创建的数组拷贝给另外一个数组。
	 利用vector重写程序，实现类似的功能。
	 * */
	void q3_32() {
		int arr[10], arr2[10];
		for (int i = 0; i < 10; i++)
			arr[i] = i;
		for (int i = 0; i < 10; i++)
			arr2[i] = arr[i];
		for (int a: arr2)
			cout << a << ", ";
		cout << endl;

		vector<int> v;
		for (int i = 0; i < 10; i++)
			v.push_back(i);
		vector<int> v2;
		for (int i = 0; i < 10; i++)
			v2.push_back(v[i]);
		for (auto a: v2)
			cout << a << ", ";
		cout << endl;
	}

	/*
	 练习 3.33:对于104 页的程序来说，如果不初始化 scores 将发生什么?

	 函数里面的内置类型是不会默认初始化的，所以数组scores里的元素值是未定义，从而自加操作的值是不确定的
	 * */

	/*
	 练习 3.34: 假定p1和p2指向同一个数组中的元素，则下面程序的功能是什么?什么情况下该程序是非法的?
		p1 += p2 - p1;
	 将p1的值更改为p2，即p1 = p2；
	 当p1和p2都是合法的指向同一个数组元素的指针，该表达式就是合法的。
	 如果其中有一个指针是非法的或者指向不同的数组元素，该表达式就是非法的。
	 * */

	/*
	 练习 3.35: 编写一段程序，利用指针将数组中的元素置为0。
	 * */
	void q3_35() {
		int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
		int* p = arr;
		auto e = end(arr);
		while (p != e) {
			*p = 0;
			p++;
		}
		for (auto a: arr)
			cout << a << ", ";
		cout << endl;
	}

	/*
	 练习3.36: 编写一段程序，比较两个数组是否相等。再写一段程序，比较两个vector对象是否相等。
	 * */
	template<typename T>
	string is_2_array_same(T* arr1, T* arr2, int len, int len2) {
		if (len != len2)
			return "false";
		for (int i = 0; i < len; i++) {
			if (arr1[i] != arr2[i])
				return "false";
		}
		return "true";
	}

	void q3_36() {
		const int arr1[5] = { 1, 2, 3, 4, 5 };
		const int arr2[5] = { 1, 2, 2, 4, 5 };
		const int arr3[5] = { 1, 2, 3, 4, 5 };
		cout << is_2_array_same(arr1, arr2, sizeof(arr1) / sizeof(arr1[0]), sizeof(arr2) / sizeof(arr2[0])) << endl;
		cout << is_2_array_same(arr1, arr3, sizeof(arr1) / sizeof(arr1[0]), sizeof(arr3) / sizeof(arr3[0])) << endl;

		vector<int> v1{ 1, 2, 3 }, v2{ 1, 2, 2 }, v3{ 1, 2, 3 };
		string res = v1 == v2 ? "true" : "false";
		cout << res << endl;
		res = v1 == v3 ? "true" : "false";
		cout << res << endl;
	}

	/*
	练习 3.37:下面的程序是何含义，程序的输出结果是什么?
		const char ca[] = { 'h', 'e', 'l', 'l', 'o' };
		const char* cp = ca;
		while (*cp) {
			cout << *cp << endl;
			++cp;
			cout << *cp << endl;
		}

	 遍历ca字符串数组，并打印数组每个元素；
	 但打印结果不确定，因为判断条件*cp是以\0为结束，但ca并没有包含\0字符，++cp会一直进行，直到内存中存放的'\0'为止。
	*/

	/*
	练习 3.38:在本节中我们提到，将两个指针相加不但是非法的，而且也没什么意义。请问为什么两个指针相加没什么意义?

	两个指针相加的结果是一个新的地址，但显然的是，这个地址是否可读、是否可写是不确定的，
	所以说两个指针相加没有什么意义
	 * */

	/*
	练习 3.39:编写一段程序，比较两个 string 对象。再编写一段程序，比较两个C风格字符串的内容。
	 * */
	string string_compare(string& a, string& b) {
		return a == b ? "true" : "false";
	}

	string cstring_compare(char* a, char* b) {
		return strcmp(a, b) == 0 ? "true" : "false";
	}

	void q3_39() {
		string s1 = "abc", s2 = "abd", s3 = "abc";
		cout << string_compare(s1, s2) << endl;
		cout << string_compare(s1, s3) << endl;

		char ch1[] = "abc", ch2[] = "abd", ch3[] = "abc";
		cout << cstring_compare(ch1, ch2) << endl;
		cout << cstring_compare(ch1, ch3) << endl;
	}

	/*
	练习 3.40:编写一段程序，定义两个字符数组并用字符串字面值初始化它们;
	 接着再定义一个字符数组存放前两个数组连接后的结果。
	 使用 strcpy和 strcat 把前两个数组的内容拷贝到第三个数组中。
	 * */
	void q3_40() {
		const char c1[] = "abc", c2[] = "def";
		auto l1 = strlen(c1), l2 = strlen(c2);
		char c3[l1 + l2 + 1];
		strcpy(c3, c1);
		strcat(c3, c2);
		cout << c3 << endl;
	}

	/*
	 练习3.41:编写一段程序，用整型数组初始化一个 vector 对象。
	 练习3.42:编写一段程序，将含有整数元素的 vector 对象拷贝给一个整型数组。

	 这两个我实在是不想写，知道有这么回事就完了，不太可能用得上，真要用的时候去查一下吧。
	 * */

	/*
	 练习 3.43:编写3个不同版本的程序，令其均能输出ia的元素。版本1使用范围for语句管理迭代过程；版本2和版本3都使用普通的for语句，
	 其中版本2要求用下标运算符，版本 3 要求用指针。
	 此外，在所有3个版本的程序中都要直接写出数据类型，而不能使用类型别名、auto关键字或decltype 关键字。
	 * */
	void q3_43() {
		int ia[3][4] = {
				{ 0, 1, 2,  3 },
				{ 4, 5, 6,  7 },
				{ 8, 9, 10, 11 }
		};

		for (const int (& p)[4]: ia) {
			for (int q: p)
				cout << q << ", ";
			cout << endl;
		}
		print_line();

		const int row = sizeof(ia) / sizeof(ia[0]), col = sizeof(ia[0]) / sizeof(ia[0][0]);
		for (int i = 0; i < row; ++i) {
			for (int j = 0; j < col; ++j) {
				cout << ia[i][j] << ", ";
			}
			cout << endl;
		}
		print_line();

		for (int (* p)[col] = ia; p != ia + row; ++p) {
			for (int* q = *p; q != *p + col; ++q)
				cout << *q << ", ";
			cout << endl;
		}
	}

	/*
	 练习3.44:改写上一个练习中的程序，使用类型别名来代替循环控制变量的类型
	 * */
	void q3_44() {
		int ia[3][4] = {
				{ 0, 1, 2,  3 },
				{ 4, 5, 6,  7 },
				{ 8, 9, 10, 11 }
		};
		using int_arr = int[4];
		for (int_arr& p: ia) {
			for (int q: p)
				cout << q << ", ";
			cout << endl;
		}
	}

	/*
	 练习 3.45:再一次改写程序，这次使用 auto 关键字。
	 * */
	void q3_45() {
		int ia[3][4] = {
				{ 0, 1, 2,  3 },
				{ 4, 5, 6,  7 },
				{ 8, 9, 10, 11 }
		};
		for (const auto& p: ia) {
			for (auto q: p)
				cout << q << ", ";
			cout << endl;
		}
		print_line();

		const int row = sizeof(ia) / sizeof(ia[0]), col = sizeof(ia[0]) / sizeof(ia[0][0]);
		for (auto p = ia; p != ia + row; ++p) {
			for (auto q = *p; q != *p + col; ++q)
				cout << *q << ", ";
			cout << endl;
		}
	}

	void main() {
//		q3_2();
//		q3_4();
//		q3_5();
//		q3_6();
//		q3_10();
//		q3_14();
//		q3_15();
//		q3_16();
//		q3_17();
//		q3_20();
//		q3_21();
//		q3_22();
//		q2_23();
//		q3_24();
//		q3_25();
//		q3_31();
//		q3_32();
//		q3_35();
//		q3_36();
//		q3_39();
//		q3_40();
//		q3_43();
//		q3_44();
		q3_45();

	}
}
