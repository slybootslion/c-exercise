#include "../head.h"
#include "./string.h"

namespace StringA2 {
// String对象中的assign()函数，可以实现字符串之间的赋值。
void test01() {
  string str, new_str;
  str = "string"; // 基本的对象赋值
  new_str.assign(str);
  cout << "str: " << str << endl;
  cout << "new_str: " << new_str << endl;

  string s1, s2;
  s1.assign(str, 1, 4); // 字符串截取从str中第一位开始，向后截取4个字符
  s2.assign(5, 'A'); // 向字符串中填充5个A
  cout << "s1: " << s1 << endl;
  cout << "s2: " << s2 << endl;
}
}
