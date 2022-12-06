#include "../head.h"
#include "vector.h"

namespace VectorA1 {
// 向数组中放入元素与移除元素

void my_print(vector<int> &var) {
  cout << "empty = " << var.empty() << " --> size = " << var.size() << endl; // empty 判空 size 尺寸大小
  cout << "capacity = " << var.capacity() << " --> max_size = " << var.max_size() << endl; // capacity 预分配的内存空间 max_size 可以存储的元素总数
  for_each(var.begin(), var.end(), [](int val) { cout << val << ' '; });
  cout << endl;
  print_line();
}

extern void test01() {
  vector<int> var{1, 2, 3};

  var.push_back(4); // 放入元素
  my_print(var);

  var.pop_back(); // 弹出一个元素
  my_print(var);

  var.resize(10); // 重新设置最大存储
  var.reserve(30); // 调整数据空间大小
  my_print(var);
}
}
