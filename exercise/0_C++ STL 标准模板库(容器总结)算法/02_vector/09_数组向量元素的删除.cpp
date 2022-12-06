#include "../head.h"
#include "vector.h"

namespace VectorA9 {
void test01() {
  vector<int> int_array{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

  // find找到元素7并删除
  vector<int>::iterator item = find(int_array.begin(), int_array.end(), 7);
  if (item != int_array.cend()) {
	int_array.erase(item); // 删除指定元素
  }

  // 删除后对数组进行遍历
  vector<int>::iterator start, end;
  end = int_array.end();
  for (start = int_array.begin(); start != end; start++) {
	cout << *start << ' ';
  }
  cout << endl;
}
}
