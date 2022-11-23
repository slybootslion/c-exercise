#include "head.h"

class String {
  public:
	explicit String(const char *str = nullptr, int max = 100);
	String(const String &other);
	~String();
	void show();
	friend String operator+(const String &op1, const String &op2);
  private:
	char *str;
};

String::String(const char *str, int max) {
  if (str) {
	unsigned long len = strlen(str) + 1;
	this->str = new char[len];
	strcpy(this->str, str);
  } else {
	this->str = nullptr;
  }
}
String::String(const String &other) {
  if (!other.str)
	this->str = other.str;
  else {
	unsigned long len = strlen(other.str) + 1;
	this->str = new char[len];
	strcpy(this->str, other.str);
  }
}
String::~String() {
  delete this->str;
}
void String::show() {
  for (char *p = this->str; p && *p; p++)
	cout << *p << " --> ascii: " << (int)*p << endl;
}
String operator+(const String &op1, const String &op2) {
  String newStr;
  if (!op1.str || !op2.str)
	return newStr;
  unsigned long size = strlen(op1.str) + strlen(op2.str) + 1;
  newStr.str = new char[size];
  strcpy(newStr.str, op1.str);
  strcat(newStr.str, op2.str);
  return newStr;
}

void p1() {
  String str1("hello");
  String str2("world");
  String str_add = str1 + str2;
  str_add.show();
}
