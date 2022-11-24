#include "my_string.h"

MyString::MyString() {
  this->m_length = 0;
  this->p_address = new char[1];
  this->p_address[0] = '\0';
}
MyString::MyString(const char *p) {
  this->m_length = strlen(p);
  this->p_address = new char[this->m_length + 1];
  strcpy(this->p_address, p);
}
MyString::MyString(const MyString &obj) {
  this->m_length = obj.m_length;
  this->p_address = new char[this->m_length + 1];
  strcpy(this->p_address, obj.p_address);
}
MyString::~MyString() {
  if (this->p_address != nullptr)
	delete[] this->p_address;
}

const char *MyString::c_str() const {
  return this->p_address;
}
int MyString::length() {
  return this->m_length;
}

ostream &operator<<(ostream &out, MyString &obj) {
  out << obj.p_address;
  return out;
}
void operator>>(const char *str, MyString &obj) {
  if (obj.p_address != nullptr)
	delete[] obj.p_address;
  obj.p_address = new char[strlen(str) + 1];
  for (int i = 0; i < strlen(str) + 1; ++i)
	obj.p_address[i] = '\0';
  strcpy(obj.p_address, str);
}

MyString &MyString::operator=(const MyString &obj) {
  if (this->p_address != nullptr) {
	delete[] this->p_address;
	this->p_address;
  }
  this->m_length = obj.m_length;
  this->p_address = new char[this->m_length + 1];
  strcpy(this->p_address, obj.p_address);
  return *this;
}
MyString &MyString::operator=(const char *p) {
  if (this->p_address != nullptr) {
	delete[] this->p_address;
	this->p_address = nullptr;
  }
  this->m_length = strlen(p);
  this->p_address = new char[this->m_length + 1];
  strcpy(this->p_address, p);
  return *this;
}
char &MyString::operator[](int index) {
  return this->p_address[index];
}

MyString &MyString::operator+=(MyString &str) {
  if (str.m_length == 0)
	return *this;
  this->m_length = this->m_length + str.m_length;
  char *temp = new char[this->m_length + 1];
  for (int i = 0; i < this->m_length + 1; i++)
	temp[i] = '\0';
  char *p = temp;
  strcat(p, this->p_address);
  strcat(p, str.p_address);
  if (this->p_address != nullptr) {
	delete[] this->p_address;
	this->p_address = nullptr;
  }
  this->p_address = temp;
  return *this;
}
MyString &MyString::operator+=(const char *s) {
  if (s == nullptr || strlen(s) == 0)
	return *this;
  this->m_length = this->m_length + (int)strlen(s);
  char *temp = new char[this->m_length + 1];
  for (int i = 0; i < this->m_length + 1; i++)
	temp[i] = '\0';
  strcat(temp, this->p_address);
  strcat(temp, s);
  if (this->p_address != nullptr) {
	delete[] this->p_address;
	this->p_address = nullptr;
  }
  this->p_address = temp;
  return *this;
}
MyString MyString::operator+(MyString &str) {
  if (str.m_length == 0)
	return *this;
  MyString temp;
  temp.m_length = this->m_length + str.m_length;
  temp.p_address = new char[temp.m_length + 1];
  for (int i = 0; i < temp.m_length + 1; i++)
	temp.p_address[i] = '\0';
  strcat(temp.p_address, this->p_address);
  strcat(temp.p_address, str.p_address);
  return temp;
}
MyString MyString::operator+(const char *str) {
  if (str == nullptr || strlen(str) == 0)
	return *this;
  MyString temp;
  temp.m_length = this->m_length + (int)strlen(str);
  temp.p_address = new char[temp.m_length + 1];
  for (int i = 0; i < temp.m_length + 1; i++)
	temp.p_address[i] = '\0';
  strcat(temp.p_address, this->p_address);
  strcat(temp.p_address, str);
  return temp;
}
bool MyString::operator==(const char *p) {
  if (p == nullptr)
	return false;
  if (strcmp(this->p_address, p) == 0)
	return true;
  return false;
}
bool MyString::operator!=(const char *p) {
  if (p == nullptr)
	return false;
  if (strcmp(this->p_address, p) != 0)
	return true;
  return false;
}
bool MyString::operator==(MyString &obj) {
  if (strcmp(this->p_address, obj.p_address) == 0)
	return true;
  return false;
}
bool MyString::operator!=(MyString &obj) {
  if (strcmp(this->p_address, obj.p_address) != 0)
	return true;
  return false;
}

