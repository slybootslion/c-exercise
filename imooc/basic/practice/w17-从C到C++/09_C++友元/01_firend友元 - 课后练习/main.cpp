#include <iostream>
using namespace std;

class FirClass;

class Test {
  public:
	Test(int a, int b) : a(a), b(b) {}
  private:
	friend class FirClass;
	int a;
	int b;
};

// 给Test类添加一个友元函数、友元成员函数、友元类分别输出Test类中的私有成员
class FirClass {
  public:
	static void print_test_private(const Test &test) {
	  cout << "test a is: " << test.a << endl;
	  cout << "test b is: " << test.b << endl;
	}
};

int main() {
  Test test(100, 110);
  FirClass::print_test_private(test);
  return 0;
}
