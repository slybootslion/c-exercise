#include "../head.h"

namespace ClassExtend02 {
class Base {
  public:
	void func1() {
	  cout << "Base::void func1()" << endl;
	}
	void func1(int param) {
	  cout << "Base::void fun1(int param)" << endl;
	}
	void myfunc() {
	  cout << "Base::void myfunc()" << endl;
	}
};
class Derived1 : public Base {};
class Derived2 : public Base {
  public:
	void myfunc() {
	  cout << "Derived2::void myfunc()" << endl;
	}
};
class Derived3 : public Base {
  public:
	void func1(int param1, int param2) {
	  cout << "Derived3::void func1(int param1, int param2)" << endl;
	}
};
class Derived4 : public Base {
  public:
	// 改变成员函数的返回值
	int func1(int param) {
	  Base::func1(10);
	  cout << "Derived4::int func1(int param)" << endl;
	  return 0;
	}
};
void main_test01() {
  Derived1 derived_1;
  derived_1.myfunc();
  // 和基类函数重名
  Derived2 derived_2;
  derived_2.myfunc();
  print_line();
}
void main_test02() {
  // 基类重载版本的函数fun1被全部隐藏，子类外部不可访问。
  Derived3 derived_3;
  derived_3.func1(10, 20);

  // 基类重载版本的函数fun1被全部隐藏，子类外部不可访问。
  Derived4 derived_4;
  derived_4.func1(10);
}
}
