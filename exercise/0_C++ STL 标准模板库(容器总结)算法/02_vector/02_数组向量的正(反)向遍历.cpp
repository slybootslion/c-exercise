#include "../head.h"
#include "vector.h"

namespace VectorA2 {
void test01() {
  // 使用数组下表实现遍历
  vector<string> str_array{"admin", "guest", "user"};
  cout << "str_array sizeof: " << str_array.capacity() << endl;
  for (int i = 0; i < str_array.size(); ++i) {
	cout << "string array --> " << str_array[i] << endl;
  }
  print_line();

  // 迭代器实现正向遍历
  vector<int> int_array{1, 2, 3, 4, 5};
  vector<int>::iterator item;
  int each = 0;
  for (item = int_array.begin(), each = 0; item != int_array.end(); ++item, ++each) {
	cout << "int_array[" << each << "] --> " << *item << endl;
  }
  print_line();

  // 迭代器实现反向遍历
  vector<int> r_int_array{1, 2, 3, 4, 5, 6, 7, 8, 9};
  vector<int>::reverse_iterator start, end; // 定义向量迭代器
  end = r_int_array.rend();
  for (start = r_int_array.rbegin(); start != end; start++) {
	cout << "r_int_array --> " << *start << endl;
  }
}
}
