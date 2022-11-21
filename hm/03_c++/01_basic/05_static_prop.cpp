#include "head.h"

namespace N05 {
class Person {
  public:
	static int s_num;
	int m_param;
	void change_parma(int param) {
	  m_param = param;
	  s_num = param;
	}
	static void change_param2(int param) {
	  s_num = param;
//	  m_param = param;
	}
	const static int m_share = 10; // 只读
  private:
	static int s_other;
	static void change_param3(int param) {
//	  m_param = param;
	  s_num = param;
	}
};

void test01() {
  Person::s_num = 100;
  cout << "Person s_sum is: " << Person::s_num << endl;

  print_line();

  Person p1, p2;
  p1.s_num = 200;

  cout << "p1.s_num = " << p1.s_num << endl;
  cout << "p2.s_num = " << p2.s_num << endl;
}

void test02() {
  Person::change_param2(100);
  Person p;
  p.change_parma(100);
  p.change_param2(200);

  cout << p.m_param << endl;
  cout << p.s_num << endl;

  cout << Person::m_share << endl;
}
}

int N05::Person::s_num = 0;
int N05::Person::s_other = 0;

void static_prop_exercise() {
//  N05::test01();
  N05::test02();
}
