#include "../head.h"
#include "my_string.h"

namespace TestMyString {
void test01() {
  MyString str1("bbb");
  MyString str2("aaa");

  str1 += str2;
  cout << "str1: " << str1 << endl;
  str1 += " hello world!";
  cout << "str1: " << str1 << endl;
}
// todo test02 and more......
}

void my_string_exercise() {
  TestMyString::test01();
}
