#include "head.h"

namespace N3 {
class String {
  public:
	explicit String(const char *str = nullptr, int max = 100);
	String(const String &other);
	~String();
	void show();
	String &operator++();
	String operator++(int);
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
String &String::operator++() {
  if (!this->str)
	return *this;
  for (char *p = this->str; p && *p; p++)
	*p += 1;
  return *this;
}
String String::operator++(int) {
  if (!this->str)
	return *this;
  String oldStr(*this);
  for (char *p = this->str; p && *p; p++)
	*p += 1;
  return *this;
}
}

void p3() {
  N3::String s1("hello");
  N3::String s3 = ++s1;
  s1.show();
  s3.show();
  cout << "============================" << endl;

  N3::String s2("world");
  N3::String s4 = s2++;
  s2.show();
  s4.show();
  cout << "============================" << endl;

}
