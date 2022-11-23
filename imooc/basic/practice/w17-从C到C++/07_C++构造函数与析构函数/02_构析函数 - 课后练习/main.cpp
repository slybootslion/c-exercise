#include <iostream>
using namespace std;

class Test {
  public:
	explicit Test(int size) {
	  this->index = 0;
	  this->data = new int[size];
	}
	~Test() {
	  delete this->data;
	}
	void insert(int d) {
	  this->data[index++] = d;
	}
	void show() {
	  for (int i = 0; i < index; i++) {
		cout << *this->data << endl;
		this->data++;
	  }
	}
  private:
	int index;
	int *data;
};

int main() {
  int i;
  Test *t = new Test(5);
  for (i = 0; i < 5; i++) {
	t->insert(i + 1);
  }
  t->show();
  return 0;
}
