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
		q2_23();

	}
}
