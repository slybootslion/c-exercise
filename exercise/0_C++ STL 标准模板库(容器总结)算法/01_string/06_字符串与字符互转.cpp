#include "../head.h"
#include "./01_string.h"

namespace StringA6 {
// 使用str.c_str()将string转换为char，使用string str()将char强转为string
void test01() {
  string str = "hello";
  const char *ptr = str.c_str(); // string 转为 char*
  cout << ptr << endl;

  // char* 转为 string
  string str1(ptr);
  cout << str1 << endl;

  // int 转为 string
  int num = 567;
  string str2 = to_string(num);
  cout << str2 << endl;
}
}
