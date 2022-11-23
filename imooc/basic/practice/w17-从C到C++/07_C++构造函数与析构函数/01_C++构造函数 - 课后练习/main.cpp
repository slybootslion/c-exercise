#include <iostream>
#include <cstring>
using namespace std;

class String {
  public:
	explicit String(const char *str = nullptr);
	String(const String &other);
	void show();
  private:
	char *str;
};

String::String(const char *str) {
  if (str) {
	unsigned long len = strlen(str) + 1;
	this->str = new char[len];
	strcpy(this->str, str);
  } else {
	this->str = nullptr;
  }
}
void String::show() {
  for (char *p = this->str; p && *p; p++)
	cout << *p << " --> ascii: " << (int)*p << endl;
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

int main() {
  String str("abcdefg");
  String str2 = str;
  str.show();
  cout << "----------------------" << endl;
  str2.show();
  return 0;
}
