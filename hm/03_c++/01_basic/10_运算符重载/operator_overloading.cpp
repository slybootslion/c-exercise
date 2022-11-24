#include "../head.h"

// 重载左移操作符(<<),使得cout可以输出对象。
namespace N10 {
class Person {
	friend ostream &operator<<(ostream &os, Person &person);
  private:
	int m_id;
	int m_age;
  public:
	Person(int id, int age) {
	  m_id = id;
	  m_age = age;
	}
	Person &operator=(const Person &person) {
	  this->m_id = person.m_id;
	  this->m_age = person.m_age;
	  return *this;
	}
};
ostream &operator<<(ostream &os, Person &person) {
  os << "ID: " << person.m_id << " Age: " << person.m_age;
  return os;
}

void test01() {
  Person person(1001, 30);
  cout << person << " | " << endl;
}

// 前置和后置(++/--)运算符重载
class Complex {
	friend ostream &operator<<(ostream &os, Complex &complex) {
	  os << "A: " << complex.ma << " B: " << complex.mb << endl;
	  return os;
	}
  private:
	int ma;
	int mb;
  public:
	Complex() {
	  ma = 0;
	  mb = 0;
	}
	Complex &operator++() {
	  ma++;
	  mb++;
	  return *this;
	}
	Complex operator++(int) {
	  Complex temp;
	  temp.ma = this->ma;
	  temp.mb = this->mb;
	  ma++;
	  mb++;
	  return temp;
	}
	Complex &operator--() {
	  ma--;
	  mb--;
	  return *this;
	}
	Complex operator--(int) {
	  Complex temp;
	  temp.ma = ma;
	  temp.mb = mb;
	  ma--;
	  mb--;
	  return temp;
	}
	void show_complex() const {
	  cout << "A: " << ma << "B: " << mb << endl;
	}
};

void test02() {
  Complex complex;
  complex++;
  cout << complex;
  ++complex;
  cout << complex;

  Complex ret = complex++;
  cout << ret;
  cout << complex;

  cout << "---------------" << endl;
  ret--;
  --ret;
  cout << "ret: " << ret;
  complex--;
  --complex;
  cout << "complex: " << complex;
}

// 类中指针
class Person2 {
	friend ostream &operator<<(ostream &os, const Person2 &person) {
	  os << "Name: " << person.p_name << " Id: " << person.m_id << " Age: " << person.m_age << endl;
	  return os;
	}
  public:
	Person2(char *name, int id, int age) {
	  this->p_name = new char[strlen(name) + 1];
	  strcpy(this->p_name, name);
	  this->m_id = id;
	  this->m_age = age;
	}
	~Person2() {
	  if (this->p_name != NULL) {
		delete[] this->p_name;
	  }
	}
	Person2 &operator=(const Person2 &person) {
	  if (this->p_name != NULL)
		delete[] this->p_name;
	  this->p_name = new char[strlen(person.p_name) + 1];
	  strcpy(this->p_name, person.p_name);
	  this->m_id = person.m_id;
	  this->m_age = person.m_age;
	  return *this;
	}
  private:
	char *p_name;
	int m_id;
	int m_age;
};

void test03() {
  Person person1(20, 20);
  Person person2(30, 30);
  cout << "person1: " << person1 << endl;
  cout << "person2: " << person2 << endl;
  person2 = person1;
  cout << "person2: " << person2 << endl;

  cout << "-----------------" << endl;

  Person2 person21("John", 20, 20);
  Person2 person22("Edward", 30, 30);
  cout << "person21: " << person21;
  cout << "person22: " << person22;
  person22 = person21;
  cout << "person22: " << person22;
}
}

namespace N11 {
// 指针运算符(*、->)重载
class Person {
  private:
	int m_param;
  public:
	explicit Person(int param) {
	  this->m_param = param;
	}
	void print_person() const {
	  cout << "Param: " << m_param << endl;
	}
};

class SmartPointer {
  public:
	Person *p_person;
	explicit SmartPointer(Person *person) {
	  this->p_person = person;
	}
	Person *operator->() {
	  return p_person;
	}
	Person &operator*() {
	  return *p_person;
	}
	~SmartPointer() {
	  if (p_person != nullptr)
		delete p_person;
	}
};

void test() {
  SmartPointer pointer(new Person(100));
  pointer->print_person();
}
}

void operator_overloading() {
//  N10::test01();
//  N10::test02();
//  N10::test03();
  N11::test();
}
