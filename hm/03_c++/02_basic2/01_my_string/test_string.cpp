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
void test02() {
  MyString str1("bbb");
  MyString str2("aaa");

  MyString str3 = str1 + str2;
  cout << "str1: " << str1 << endl;
  cout << "str2: " << str2 << endl;
  cout << "str3: " << str3 << endl;

  cout << "-------------------" << endl;

  MyString str4 = str1 + "hello world!";
  cout << "str1: " << str1 << endl;
  cout << "str4: " << str4 << endl;
}

void test03() {
  MyString str1("bbb");
  MyString str2("aaa");
  cout << "str1: " << str1 << endl;
  cout << "str2: " << str2 << endl;
  cout << "-------------------" << endl;
  str1 = str2;
  cout << "str1: " << str1 << endl;
  cout << "str2: " << str2 << endl;
  cout << "-------------------" << endl;
  cout << "[]: ";
  for (int i = 0; i < str1.length(); i++)
	cout << str1[i];
  cout << endl;
}

void test04() {
  MyString str1("bbb");
  MyString str2("aaa");
  if (str1 != str2)
	cout << "不相等" << endl;
  if (str1 != "ccc")
	cout << "不相等" << endl;

  str2 = str1;
  if (str1 == str2)
	cout << "相等" << endl;
  if (str1 == "bbb")
	cout << "相等" << endl;
}

void test05() {
  MyString str1("bbb");
  MyString str2 = str1;
  MyString str3(str1);

  cout << "str1: " << str1 << endl;
  cout << "str2: " << str2 << endl;
  cout << "str3: " << str3 << endl;
}

void test06() {
  MyString str;
  "hello world" >> str;
  cout << "str: " << str << endl;
}
}

void my_string_exercise() {
//  TestMyString::test01();
//  TestMyString::test02();
//  TestMyString::test03();
//  TestMyString::test04();
//  TestMyString::test05();
  TestMyString::test06();
}
