#include "chapter07.h"

#include <utility>

namespace chapter07
{
	/*
	 练习7.1：使用2.6.1节练习定义的Sales_data类为1.6节（第21页）的交易处理程
	 序编写一个新版本。
	 */
	struct Sales_data
	{
		Sales_data& combine(const Sales_data& rhs);

		string isbn() const {
			return bookNo;
		}

		string bookNo;
		unsigned int units_sold{};
		double revenue{};
	};

	Sales_data& Sales_data::combine(const Sales_data& rhs) {
		units_sold += rhs.units_sold;
		revenue += rhs.revenue;
		return *this;
	}

	istream& read(istream& is, Sales_data& sd) {
		double p;
		is >> sd.bookNo >> sd.units_sold >> p;
		sd.revenue = p * sd.units_sold;
		return is;
	}

	ostream& print(ostream& os, const Sales_data& sd) {
		double avg_p{ 0.0 };
		if (sd.units_sold > 0)
			avg_p = sd.revenue / sd.units_sold;
		os << sd.bookNo << " "
		   << sd.units_sold << " "
		   << sd.revenue << " "
		   << avg_p;
		return os;
	}

	void q7_1() {
		Sales_data total;
		if (read(cin, total)) {
			Sales_data trans;
			while (read(cin, trans)) {
				if (total.bookNo == trans.bookNo) {
					total.units_sold += trans.units_sold;
					total.revenue += trans.revenue;
				} else {
					print(cout, total) << endl;
					total = trans;
				}
			}
			print(cout, total) << endl;
		} else {
			cerr << "No data!" << endl;
		}
	}


	/*
	 练习7.2：曾在2.6.2的练习（第67页）中编写了一个Sales_data类，请向这个类
	 添加combine和isbn成员。

	 直接在上面修改
	*/

	/*
	 练习7.3：修改7.1.1节（第229页）的交易处理程序，令其使用这些成员。
	 * */
	void q7_3() {
		Sales_data total;
		if (read(cin, total)) {
			Sales_data trans;
			while (read(cin, trans)) {
				if (total.isbn() == trans.isbn()) {
					total.combine(trans);
				} else {
					print(cout, total) << endl;
					total = trans;
				}
			}
			print(cout, total) << endl;
		} else {
			cerr << "No data!" << endl;
		}
	}

	/*
	 练习7.4:编写一个名为 Person 的类，使其表示人员的姓名和住址。使用 string对象存放这些元素，接下来的练习将不断充实这个类的其他特征。
	 练习7.5:在你的Person类中提供一些操作使其能够返回姓名和住址。这些函数是否应该是 const的呢?解释原因。

	 应该加const，原因不知道。
	 * */
	class Person
	{
	public:
		Person() = default;

		Person(string name, string address) : name(std::move(name)), address(std::move(address)) {
		}

		[[nodiscard]] string getName() const {
			return name;
		}

		[[nodiscard]] string getAddress() const {
			return address;
		}

		void in_Person(const string& n, const string& a) {
			this->name = n;
			this->address = a;
		}

		void printPerson() const {
			cout << "name: " << getName() << endl;
			cout << "address: " << getAddress() << endl;
		}

	private:
		string name;
		string address;
	};

	void q7_4_5() {
		Person p("zhang san", "shanghai");
		cout << "name: " << p.getName() << endl;
		cout << "address: " << p.getAddress() << endl;
	}

	/*
	 练习 7.6:对于函数 add、read 和print，定义你自己的版本。

	 直接用之前的题做。
	 * */

	Sales_data add(const Sales_data& lhs, const Sales_data& rhs) {
		Sales_data temp = lhs;
		return temp.combine(rhs);
	}

	/*
	 练习 7.7:使用这些新函数重写 7.12节第233页)练习中的交易处理程序
	 * */
	void q7_7() {
		Sales_data total;
		if (read(cin, total)) {
			Sales_data trans;
			while (read(cin, trans)) {
				if (total.isbn() == trans.isbn()) {
					total = add(total, trans);
				} else {
					print(cout, total) << endl;
					total = trans;
				}
			}
			print(cout, total) << endl;
		} else {
			cerr << "No data!" << endl;
		}
	}

	/*
	 练习7.8:为什么read函数将其Sales_data参数定义成普通的引用，而print将其参数定义成常量引用?

	 因为read需要改变传入的Sales_data对象，print无需改变，为了使得print也能够处理常量对象，必须将其参数定义成常量引用。
	 * */

	/*
	 练习 7.9:对于7.1.2节(第233 页)练习中的代码，添加读取和打印Person对象的操作。

	 直接修改之前的题。
	 * */

	void q7_9() {
		Person p;
		p.in_Person("zhang san", "shanghai");
		p.printPerson();
	}

	/*
	 练习 7.10:在下面这条 if 语句中，条件部分的作用是什么?
	 	if (read(read(cin. data1), data2))

	 先从标准输入读取数据存入data1，然后继续从标准输入读取数据存入data2，判断此时标准输入cin的状态是否合法。
	 	等价于：
	 	std::istream& is1=read(cin,data1);
	 	std::istream& is2=read(is1,data2);
	 * */

	void main() {
//		q7_1();
//		q7_3();
//		q7_4_5();
//		q7_7();
		q7_9();

	}
}
