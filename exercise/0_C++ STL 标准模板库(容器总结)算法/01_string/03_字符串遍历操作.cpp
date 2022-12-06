#include "../head.h"
#include "./string.h"

namespace StringA3 {
// 通过使用str.size()函数获取到字符的具体个数，然后循环遍历输出这些字符串。
void test01() {
  string str = "hello c++";

  // 第一种遍历：如果字符串越界，会直接挂掉
  for (int i = 0; i < str.size(); ++i) {
    cout << str[i] << endl;
  }

  print_line();

  // 第二种遍历：如果字符串越界，会抛出异常
  try {
    for (int i = 0; i < str.size(); ++i) {
      cout << str[i] << endl;
    }
  } catch (out_of_range &e) {
    cout << "异常类型：" << e.what() << endl;
  }
}
}

