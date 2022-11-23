#include <iostream>

using namespace std;

class Test {
  public:
	Test(int a, int b) : a(a), b(b) {}
	void function() {
	  a++;
	  b++;
	}
	static void static_function(Test &obj) {
	  obj.a++;
	  obj.b++;
	}
	void show() {
	  cout << "a : " << a << endl;
	  cout << "b : " << b << endl;
	}
  private:
	int a;
	int b;
};

int main() {
  Test obj1(1, 2);
  Test obj2(3, 4);

  obj1.function();
  obj2.function();
  Test::static_function(obj1);

  obj1.show();
  obj2.show();
  return 0;
}

