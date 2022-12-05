#include "../head.h"
#include "./01_string.h"

namespace StringA4 {
// 使用append()添加字符串，使用insert()插入字符串，使用erase()删除指定范围字符串。
void test01() {
  string str1("hello "), str2("world");
  str1.append(str2); // 将str2的内容追加到str1后面
  str1.append(str2, 1, 3); // 将str2内容第1个到第3个字符追加到str1后面
  str1.append(5, 'A'); // 将str1子串里追加5个A
  cout << "str1: " << str1 << endl; // str1: hello worldorlAAAAA

  string str3 = "this is ok";
  string str4 = str3.substr(1, 3); // 截取子串 => this 从第1个开始截取3个字符
  string str5 = str3.substr(1, 5); // 截取子串 => his i
  cout << "str4: " << str4 << endl;
  cout << "str5: " << str5 << endl;

  string str6 = "a real steel";
  str6.erase(5); // 从第5个字符开始向后删除所有
  str6.erase(0, 3); // 从第0个字符开始向后删除4个

  cout << "str6: " << str6 << endl; // ea

  string str7 = "hello world";
  str7.insert(2, "123"); // 在下标2处插入字符串"123"

  cout << "str7: " << str7 << endl; // he123llo world
}
}
