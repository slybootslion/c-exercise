#include "../head.h"
#include "vector.h"

namespace VectorA4 {
// 向数组向量中插入元素 push_back() 与 insert()
void test01() {
  vector<string> str_array{"admin", "guest", "user"};

  str_array.push_back("django"); // 插入元素
  str_array.push_back("python");
  str_array.pop_back(); // 弹出元素

  str_array.insert(str_array.begin() + 2, "ruby"); // 在数组索引2的位置插入元素
  str_array.insert(str_array.end(), "c++"); // 在数组最后插入元素

  for (int x = 0; x < str_array.size(); x++)
	cout << "str_array[" << x << "] --> " << str_array[x] << endl;
}
}
