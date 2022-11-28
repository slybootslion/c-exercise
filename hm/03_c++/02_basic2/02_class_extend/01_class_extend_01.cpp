#include "../head.h"

namespace ClassExtend01 {
class Base {
  public:
	int m_param;
	Base() : m_param(0) {}
	void print() { cout << m_param << endl; }
};
class Derived : public Base {
  public:
	int m_param;
	Derived() : m_param(10) {}
	void print() {
	  cout << "base m_param: " << Base::m_param << endl;
	  cout << "derived param: " << m_param << endl;
	}
	int &get_base_param() { return Base::m_param; }
};

int main_test01() {
  Derived derived;
  cout << derived.m_param << endl;
  derived.print();
  derived.get_base_param() = 100;
  cout << "base:m_param: " << derived.get_base_param() << endl;
  return EXIT_SUCCESS;
}
}
