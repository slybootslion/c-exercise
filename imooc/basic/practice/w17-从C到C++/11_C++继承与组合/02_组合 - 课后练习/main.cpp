#include <iostream>

using namespace std;

class PrintClass {
  public:
	explicit PrintClass(const string &str) {
	  this->str = str;
	}
	void print_string() {
	  cout << this->str << endl;
	}
  private:
	string str;
};

class Test {
  private:
	PrintClass pc;
  public:
	explicit Test(const string &str): pc(str){}
	void show_str() {
	  pc.print_string();
	}
};

int main() {
  Test t("铁锤有一个苹果电脑!");
  t.show_str();
  return 0;
}
