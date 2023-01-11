#include "Function_ex.h"

namespace FunctionEx
{
	void print(string& content) {
		cout << content << endl;
	}

	// 函数指针
	void callPrint(void (* f)(string&), string& param) {
		f(param);
	}

	class MyFunction
	{
	public:
		int operator()(int x, int y) {
			return x + y;
		}

		double operator()(double x, double y) {
			return x * y;
		}
	};

	int add(int x, int y) {
		return x + y;
	}

	void callFunction(function<int(int, int)> f, int param1, int param2) {
		cout << f(param1, param2) << endl;
	}

	auto getFunction() {
		auto print = [](auto param)
		{
			cout << param << endl;
		};
		return print;
	}

	class ORM
	{
	public:
		ORM* Select(const char* param) {
			cout << param << endl;
			return this;
		}

		ORM* From(const char* param) {
			cout << param << endl;
			return this;
		}

		ORM* Where(const char* param) {
			cout << param << endl;
			return this;
		}

		ORM* OrderBy(const char* param) {
			cout << param << endl;
			return this;
		}
	};

	void main() {
		string content{ "allen" };
		// 使用函数指针，吧print方法当作参数直接传递给callPrint方法
		callPrint(print, content);

		MyFunction func;
		cout << func(12, 13) << " " << func(3.2, 19.8) << endl;

		callFunction(add, 12, 13);
		callFunction(func, 12, 13);

		auto print = getFunction();
		print(123);
		print("linlun");

		ORM* orm{ new ORM() };
		cout << endl;
		orm->Select("username")->From("user")->Where("id = 123")->OrderBy("createTime");
	}
}
