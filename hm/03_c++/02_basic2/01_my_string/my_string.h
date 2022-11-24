#ifndef INC_02_BASIC2_01_MY_STRING_MY_STRING_H_
#define INC_02_BASIC2_01_MY_STRING_MY_STRING_H_

#include "../head.h"

class MyString {
  private:
	char *p_address;
	int m_length;
  public:
	MyString();
	MyString(const char *p);
	MyString(const MyString &obj);
	~MyString();

	const char *c_str() const;
	int length();

	friend ostream &operator<< (ostream &cout, MyString &obj);
	friend void operator>>(const char *str, MyString &obj);

	MyString &operator=(const MyString &obj);
	MyString &operator=(const char *p);
	char &operator[](int index);

	MyString &operator+=(MyString &str);
	MyString &operator+=(const char *s);
	MyString operator+(MyString &str);
	MyString operator+(const char *str);

	bool operator==(const char *p);
	bool operator!=(const char *p);
	bool operator==(MyString &obj);
	bool operator!=(MyString &obj);
};

#endif //INC_02_BASIC2_01_MY_STRING_MY_STRING_H_
