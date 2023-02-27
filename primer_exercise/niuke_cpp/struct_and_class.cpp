#include "struct_and_class.h"

namespace struct_and_class
{
	// CC13 KiKi定义电子日历类
	class TDate
	{
	private:
		int year, month, day;
	public:
		TDate(int month, int day, int year) : year(year), month(month), day(day) {
			cout << day << "/" << month << "/" << year << endl;
		}
	};

	void cc13() {
		int a, b, c;
		cin >> a >> b >> c;
		TDate t(b, c, a);
	}

	// CC15 牛牛的书
	class Book
	{
	public:
		string name;
		double price;

		Book(string& name, double price) : name(name), price(price) {
		}
	};

	bool book_sort(Book& a, Book& b) {
		return a.price < b.price;
	}

	void cc15() {
		int n;
		cin >> n;
		vector<Book> v;
		while (n--) {
			string name;
			double price;
			cin >> name >> price;
			Book b(name, price);
			v.push_back(b);
		}

		sort(v.begin(), v.end(), book_sort);

		for (const auto& b : v)
			cout << b.name << endl;
	}

	void main() {
//		cc13();
		cc15();

	}
}
