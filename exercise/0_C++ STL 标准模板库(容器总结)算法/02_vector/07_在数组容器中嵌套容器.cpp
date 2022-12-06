#include "../head.h"
#include "vector.h"

namespace VectorA7 {
void test01() {
  vector<vector<int>> var;
  vector<int> v1;
  vector<int> v2;

  for (int x = 0; x < 5; x++) {
	v1.push_back(x);
	v2.push_back(x + 10);
  }
  var.push_back(v1);
  var.push_back(v2);

  // 遍历容器数据
  for (vector<vector<int>>::iterator item = var.begin(); item != var.end(); item++) {
	for (vector<int>::iterator i = (*item).begin(); i != (*item).end(); i++) {
	  cout << *i << " ";
	}
	cout << endl;
  }
}
}
