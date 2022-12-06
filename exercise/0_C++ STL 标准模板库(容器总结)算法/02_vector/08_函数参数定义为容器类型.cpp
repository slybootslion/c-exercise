#include "../head.h"
#include "vector.h"

namespace VectorA8 {
void my_print_vector(vector<int> &var) {
  for (vector<int>::iterator item = var.begin(); item != var.end(); item++) {
	cout << (*item) << ' ';
  }
  cout << endl;
}

void test01() {
  vector<int> var;
  int array[] = {1, 2, 3, 4, 5};

  // 两种不同的容器构造方式
  vector<int> v1(array, array + sizeof(array) / sizeof(array[0]));
  vector<int> v2(v1.begin(), v1.end());
  cout << "v2: "; my_print_vector(v2); // 打印v2中的内容
  print_line();

  vector<int> v3(10, 20); // 生成容器，里面包含10个20
  cout << "v3: ";my_print_vector(v3);
  print_line();

  vector<int> v4; // 赋值的使用
  v4.assign(v3.begin(), v3.end());
  cout << "v4: ";my_print_vector(v4);
  print_line();

  v4.swap(v2); // v2与v4容器内容互换
  cout << "v4: ";my_print_vector(v4);
  cout << "v2: ";my_print_vector(v2);
}
}
