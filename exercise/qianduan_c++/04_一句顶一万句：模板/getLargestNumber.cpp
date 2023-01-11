#include "getLargestNumber.h"

namespace GetLargestNumber
{
	template<typename T>
	T getLargestNumber(const vector<T>& vect) {
		T largestNumber{ vect.at(0) };
		for (auto& val: vect) {
			if (val > largestNumber) largestNumber = val;
		}
		return largestNumber;
	}

	template<typename T1, typename T2>
	auto getBiggerNum(T1 param1, T2 param2) {
		return param1 > param2 ? param1 : param2;
	}

	void main() {
		vector<int> vect1{ 1, 2, 3, 4, 5, 9, 8, 7, 6, 0 };
		vector<double> vect2{ 1.1, 2.2, 3.3, 4.4, 9.9, 8.8, 7.7, 6.6 };
		auto result1 = getLargestNumber(vect1);
		auto result2 = getLargestNumber(vect2);
		cout << result1 << endl;
		cout << result2 << endl;

		int a{ 123 };
		double b{ 987.36 };
		auto result = getBiggerNum(a, b);
		cout << result << endl;
	}
}

namespace KeyValPair
{
	template<typename T>
	class KeyValPair
	{
	public:
		KeyValPair(string k, T v) : key{ k }, value{ v } {
		};
		string key;
		T value;
	};

	template<typename T>
	class Dic
	{
	public:
		vector<KeyValPair<T>> vect;

		Dic() = default;

		void PushBack(KeyValPair<T> val) {
			vect.push_back(val);
		}

		auto operator[](string key) {
			for (KeyValPair<T>& pair: vect) {
				if (pair.key == key) {
					return pair.value;
				}
			}
			return 0;
		}
	};

	void main() {
		Dic<int> dic;
		dic.PushBack({ "test1", 123 });
		dic.PushBack({ "test2", 456 });
		dic.PushBack({ "test3", 789 });
		cout << dic["test2"] << endl;
	}
}

namespace Template3
{
	template<typename T1>
	class Test
	{
	public:
		T1 typeVal;

		Test(T1 val) : typeVal{ val } {
		};

		template<typename T2>
		void Print(T2 t) {
			cout << typeVal << t << endl;
		}
	};

	template<typename T = int, T WIDTH = 123>
	class MyType
	{
	public:
		MyType() = default;

		T getWidth() {
			return WIDTH;
		}
	};

	void main() {
		Test<string> testObj{ "test template class:" };
		testObj.Print("allen");
		testObj.Print(89.36);

		MyType obj;
		cout << obj.getWidth() << endl;
//		MyType<double, 456.1> obj2;
//		cout << obj2.getWidth() << endl;
	}
}
