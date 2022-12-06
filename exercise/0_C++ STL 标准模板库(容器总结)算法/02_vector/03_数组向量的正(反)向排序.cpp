#include "../head.h"
#include "vector.h"

namespace VectorA3 {

bool my_compare(int value1, int value2) {
  return value1 > value2;
}

void test01() {
  vector<int> *int_array = new vector<int>;
  // 生成10个随机数用于测试
  unsigned seed = time(0);
  srand(seed);
  for (int x = 0; x < 10; x++) {
	int_array->push_back(rand() % 100);
  }

  // 遍历的方式实现 正向排序
  sort(int_array->begin(), int_array->end());
  // 迭代器遍历
  vector<int>::const_iterator item = int_array->cbegin(); // cbegin()该函数用于指向向量容器的第一个元素。返回常量迭代器
  while (item != int_array->cend()) { // cend()指向向量中的 past-the-last 元素(最后一个元素之后的元素)
	cout << *item << " ";
	item++;
  }
  cout << endl;
  print_line();

  // 遍历的方式实现 反向排序
  sort(int_array->begin(), int_array->end(), my_compare);
  vector<int>::const_iterator item_1 = int_array->cbegin();
  while (item_1 != int_array->cend()) {
	cout << *item_1 << " ";
	item_1++;
  }
}
}
