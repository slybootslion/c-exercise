#include "../head.h"
#include "vector.h"

namespace VectorA6 {
class MyAnimal {
  public:
	string name;
	int id;
  public:
	MyAnimal(const string& name, int id) {
	  this->name = name;
	  this->id = id;
	}
};

void test01() {
  MyAnimal *pDog = new MyAnimal("dog", 1);
  MyAnimal *pMonkey = new MyAnimal("monkey", 2);
  MyAnimal *pSnake = new MyAnimal("snake", 3);

  vector<MyAnimal *> var;
  var.push_back(pDog);
  var.push_back(pMonkey);
  var.push_back(pSnake);

  vector<MyAnimal *>::iterator start, end;
  end = var.end();
  for (start = var.begin(); start != end; start++) {
	cout << "id: " << (*start)->id << "--->" << "name: " << (*start)->name << endl;
  }
}
}
