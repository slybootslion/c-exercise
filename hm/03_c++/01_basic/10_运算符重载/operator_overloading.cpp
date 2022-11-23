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
}

void operator_overloading() {
//  N10::test01();
  N10::test02();
}
