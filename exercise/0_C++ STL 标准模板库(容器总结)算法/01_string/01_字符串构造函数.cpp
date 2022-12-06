#include "../head.h"
#include "./string.h"

namespace StringA1 {
// 可以通过构造函数完成初始化字符串。
void test01() {
  string str("hello c++"); // 定义一个字符串
  string str_1(str); // 构造函数，将str中的内容全部复制到str_1
  string str_2(str, 2, 5); // 构造函数，从字符串str的第2个元素开始，复制5个元素，赋值给str_2
  string str_3(str.begin(), str.end()); // 复制字符串str所有元素，并赋值给str_3
  char ch[] = "string";
  string str_4(ch, 3); // 将字符串ch的前5个元素复制给str_4
  string str_5(5, 'x'); // 将5个'x'组成的字符串"xxxxx"赋值给str_5

  cout << "str: " << str << endl;
  cout << "str_1: " << str_1 << endl;
  cout << "str_2: " << str_2 << endl;
  cout << "str_3: " << str_3 << endl;
  cout << "str_4: " << str_4 << endl;
  cout << "str_5: " << str_5 << endl;
}
}
