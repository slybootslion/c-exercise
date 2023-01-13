#include <variant>
#include "tools.h"

namespace Tools
{
	static inline void ltrim(string& s) {
		auto endPosition = find_if(s.begin(), s.end(), [](unsigned char ch)
		{
			return !isspace(ch);
		});
		s.erase(s.begin(), endPosition);
	}

	static inline void rtrim(string& s) {
		auto startPosition = find_if(s.rbegin(), s.rend(), [](unsigned char ch)
		{
			return !isspace(ch);
		}).base();
		s.erase(startPosition, s.end());
	}

	static inline void trim(string& s) {
		rtrim(s);
		ltrim(s);
	}

	void string_tool() {
		auto str1{ "   liulun   "s }; //加了s尾缀，str1就是std:string类型，不然就是const char*
		trim(str1); //c++标准库中没有trim，使用的是自己实现的。
		cout << str1 << endl; //输出：liulun

		int num1 = stoi("1237"s);
		double num2 = stod("123.45"s);
		cout << num1 << " " << num2 << endl;

		auto str2 = to_string(num1);
		auto str3 = to_string(num2);
		cout << str2 << " " << str3 << endl;

		auto str4{ "他1926年8月17日出生，2022年11月30日逝世，是江苏省扬州市人。"s };
		cout << str4.substr(21, 19) << endl;
		cout << str4.find("2022") << endl;
//		cout << format("他{0}年8月17日出生，{1}年11月30日逝世，他{0}年8月17日出生，{1}年11月30日逝世。", "1926", "2022")
//			 << endl;
// gcc 用不了
	}

	void isPhoneNumber() {
		// regx_constants::icase不区分大小写
		regex reg{ R"(^(13[0-9]|14[01456879]|15[0-35-9]|16[2567]|17[0-8]|18[0-9]|19[0-35-9])\d{8}$)",
				   regex_constants::icase };
		bool flag = regex_match("18158135758", reg);
		cout << "Is phone number: " << (flag ? "true" : "false") << endl;
	}

	// 使用正则表达式替换命中的匹配项
	void replaceByRegex() {
		string str = "等忙完这一阵子，就可以接着忙下一阵子了。";
		regex reg{ R"(一.{2}子)" }; // 一个中文字符相当于两个英文字符
		cout << regex_replace(str, reg, "一会儿") << endl;
	}

	// 使用正则表达式搜索字符串
	void regexSearch() {
		string str = "他1926年8月17日出生，2022年11月30日逝世，是江苏省扬州市人。";
		smatch result;
		regex reg{ R"(\d{4})" };
		string::const_iterator iterStart = str.begin();
		string::const_iterator iterEnd = str.end();
		while (regex_search(iterStart, iterEnd, result, reg)) {
			cout << result[0] << " ";
			iterStart = result[0].second; // 更新搜索位置，搜索剩下的字符
		}
	}

	void reg() {
		isPhoneNumber();
		replaceByRegex();
		regexSearch();
	}

	void getRangeRand(int min, int max) {
		random_device dev; // 创建random_device对象
		unsigned int result = (dev() % (max + 1 - min)) + min; // [min, max]
		cout << result << endl;
	}

	void get5RandNumByRand() {
		srand(time(nullptr));
		cout << rand() << " "
			 << rand() << " "
			 << rand() << " "
			 << rand() << " "
			 << rand() << endl;
	}

	void getRandNumByRandomDevice() {
		random_device dev;
		cout << dev() << " "
			 << dev() << " "
			 << dev() << " "
			 << dev() << " "
			 << dev() << endl;
	}

	void random_ex() {
		getRangeRand(100, 200);
		get5RandNumByRand();
		getRandNumByRandomDevice();
	}

	void variant_ex() {
		variant<int, double, string> myVariant;
		myVariant = 12;
		myVariant = 3.14;
		myVariant = "hello";
		cout << myVariant.index() << endl;

		myVariant = 3.33;
		cout << myVariant.index() << endl;
	}

	void main() {
//		string_tool();
//		reg();
//		random_ex();
		variant_ex();
	}
}
