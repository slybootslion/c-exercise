#include "head.h"

namespace N2 {
class String {
  public:
	explicit String(const char *str = nullptr, int max = 100);
	String(const String &other);
	~String();
	void show();
	String operator+(const String &op2);
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
String String::operator+(const String &op2) {
  String new_str;
  if (!this->str || !op2.str)
	return new_str;
  unsigned long size = strlen(this->str) + strlen(op2.str) + 1;
  new_str.str = new char[size];
  strcpy(new_str.str, this->str);
  strcat(new_str.str, op2.str);
  return new_str;
}
}

void p2() {
  N2::String s1("hello");
  N2::String s2(" world");
  N2::String s3 = s1 + s2;
  s3.show();
}
