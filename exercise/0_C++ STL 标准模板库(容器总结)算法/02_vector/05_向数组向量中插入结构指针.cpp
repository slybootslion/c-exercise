#include "../head.h"
#include "vector.h"

namespace VectorA5 {
typedef struct {
  int id;
  char sz_name[20];
} Person, *Ptr;

void test01() {
  vector<Person> ary[10];

  Person p1 = {1, "admin"};
  Person p2 = {2, "user"};
  Person p3 = {3, "guest"};

  ary->push_back(p1);
  ary->push_back(p2);
  ary->push_back(p3);

  auto item = ary->begin();
  for (; item != ary->end(); item++)
	cout << "id: " << (*item).id << " --> name: " << (*item).sz_name << endl;
}
}
