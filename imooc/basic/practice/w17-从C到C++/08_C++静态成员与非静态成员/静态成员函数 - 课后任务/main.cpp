#include <iostream>
using namespace std;

class StaticClass {
  private:
	StaticClass() {
	  this->num = 100;
	}
  public:
	static StaticClass init_static_object() {
	  StaticClass *p = new StaticClass;
	  return *p;
	}
	int num;
};

int main() {
  StaticClass obj = StaticClass::init_static_object();
  cout << obj.num << endl;
  return 0;
}
