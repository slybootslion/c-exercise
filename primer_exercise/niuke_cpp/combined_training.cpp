#include "combined_training.h"

#include <utility>
#include <vector>
#include <algorithm>

namespace combined_training
{
	// CPP52 统计字符串中各类型字符的个数
	void cpp52() {
		int letter = 0;
		int digit = 0;
		int space = 0;
		int other = 0;

		char buf[1024] = { 0 };
		cin.getline(buf, sizeof(buf));

		// write your code here......
		int cc = 0;
		for (auto c: buf) {
			if (c == '\0') break;
			if (isalnum(c)) {
				if (isdigit(c)) digit++;
				else letter++;
			} else if (isspace(c)) space++;
			else other++;
		}

		cout << "letter:" << letter << " digit:" << digit << " space:" << space <<
			 " other:" << other << endl;
	}

	// CPP53 个人所得税计算程序
	// 应纳税额 ＝（工资薪金所得－扣除数）× 适用税率－速算扣除数。其中，扣除数为3500元。
	class Employee {

	private:
		string name;
		double salary;
		// write your code here......
	public:
		Employee(string name, double salary): name(std::move(name)), salary(salary) {}
		string getName() {
			return name;
		}
		[[nodiscard]] double getSalary() const {
			return salary;
		}
		double percent{};
		double deduct{};
	};

	bool compare (const Employee& e1, const Employee& e2) {
		return e1.getSalary() > e2.getSalary();
	}

	void make_deduct (Employee& e) {
		if (e.getSalary() <= 1500) {
			e.percent = 0.03;
			e.deduct = 0;
		} else if (e.getSalary() <= 4500) {
			e.percent = 0.1;
			e.deduct = 105;
		} else if (e.getSalary() <= 9000) {
			e.percent = 0.2;
			e.deduct = 555;
		} else if (e.getSalary() <= 35000) {
			e.percent = 0.25;
			e.deduct = 1005;
		} else if (e.getSalary() <= 55000) {
			e.percent = 0.3;
			e.deduct = 2755;
		} else if (e.getSalary() <= 80000) {
			e.percent = 0.35;
			e.deduct = 5505;
		} else {
			e.percent = 0.45;
			e.deduct = 13505;
		}
	}

	auto format_double_val(double val) {
		auto str = std::to_string(val);
		return str.substr(0, str.find('.') + 2 + 1);
	}
	void cpp53() {
		vector<Employee> v;
		Employee e1 = Employee("张三", 6500);
		Employee e2 = Employee("李四", 8000);
		Employee e3 = Employee("王五", 100000);

		v.push_back(e1);
		v.push_back(e2);
		v.push_back(e3);

		sort(v.begin(), v.end(), compare);

		for (Employee e : v) {
			double tax = 0;
			make_deduct(e);
			tax = (e.getSalary() - 3500) * e.percent - e.deduct;
			cout << e.getName() + "应该缴纳的个人所得税是：" + format_double_val(tax) << endl;
		}
	}

	void main() {
//		cpp52();
		cpp53();

	}
}
