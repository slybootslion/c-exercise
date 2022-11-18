#include "head.h"

void print_line() {
  cout << "---------------------" << endl;
}

class Person {
 public:
  Person() {
	cout << "no param constructor!" << endl;
	m_age = 10;
  }
  Person(int age) {
	cout << "param constructor!" << endl;
	m_age = age;
  }
  Person(const Person &person) {
	cout << "copy constructor!" << endl;
	m_age = person.m_age;
  }
  ~Person() {
	cout << "destruction!" << endl;
  }
 public:
  int m_age;
};

void test01() {
  Person p(10);
  print_line();
  Person p1(p);
  print_line();
  Person p2 = Person(p);
  print_line();
  Person p3 = p; // 相当于上面那条
  print_line();
}

void do_bussiness(Person p) {}

void test02() {
  Person p(10);
  print_line();
  do_bussiness(p);
}

Person my_bussiness() {
  Person p(10);
  cout << "局部内 p:" << (int *)&p << endl;
  return p;
}

void test03() {
  Person p = my_bussiness();
  cout << "局部外 p:" << (int *)&p << endl;
}

void constructor_function_exercise() {
//  test01();
//  test02();
  test03();
}
