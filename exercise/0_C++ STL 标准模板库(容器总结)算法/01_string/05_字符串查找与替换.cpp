#include "../head.h"
#include "./01_string.h"

namespace StringA5 {
// 使用find()可查找字符串第一次出现的位置，使用compare比较字符串，使用replace()替换字符串。
void test01() {
  string str1("Source Code"), str2("Source Code"), str3("source code");
  int x;

  x = str1.find("ur");
  if (x != string::npos) {
    cout << x << endl; // 1
    cout << str1.substr(x) << endl; // ource Code
  }

  x = str1.find("Code", 2); // 从str1第2位开始，查找字符串”Code“
  if (x != string::npos) {
    cout << x << endl; // 7
    cout << str1.substr(x) << endl; // Code
  }

  // 查找urc字符串最先出现的位置
  if ((x = str1.find_first_of("urc")) != string::npos) {
    cout << x << endl; // 2
  }

  // 比较两个字符串是否相等
  cout << str1.compare(str2) << endl; // 0 相等
  cout << str1.compare(str3) << endl; // -32

  string str4 = "hello world";
  str4.replace(1, 3, "abcde"); // 从1处开始替换3个字符
  cout << str4 << endl; // habcdeo world
}

// 通过find()查找指定通配符，然后用substr()灵活的提取左面或右面的字符串
void test02() {
  string email = "admin@xxxx.com";
  int pos = email.find('@');

  string username = email.substr(0, pos); // 提取出用户名
  cout << username << endl; // admin

  string mail = email.substr(pos + 1);
  cout << mail << endl; // xxxx.com
}
}
