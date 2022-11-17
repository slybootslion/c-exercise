#include "head.h"

class Circle {
 public:
  double mr;
 public:
  void set_r(double r) {
	mr = r;
  }
  double get_l() {
	return 2 * 3.14 * mr;
  }
};

void circle_circumference_exercise() {
  Circle circle;
  circle.set_r(100);
  double cir = circle.get_l();
  cout << "circumference = " << cir << endl;
}

class Student {
 public:
  void set_name(string n) {
	name = n;
  }
  void set_id(int _id) {
	id = _id;
  }
  void print_stu() {
	cout << "name: " << name << "\nid: " << id << endl;
  }
 private:
  string name;
  int id;
};

void student_class_exercise() {
  Student student;
  student.set_name("zhangsan");
  student.set_id(1);
  student.print_stu();
}

class Maker {
 private:
  string name;
  int age;
 public:
  void init() {
	name = "zhangsan";
	age = 18;
  }
  void set_name(string n) {
	name = n;
  }
  void set_age(int a) {
	if (a < 0 || a > 100) return;
	age = a;
  }
  string get_name() {
	return name;
  }
  int get_age() {
	return age;
  }
  void print_maker() {
	cout << "name: " << name << "\tage: " << age << endl;
  }
};

void class_operation() {
	Maker maker;
	maker.init();
	maker.print_maker();
	maker.set_name("lisi");
	maker.set_age(20);
	maker.print_maker();
}

void class_basic_exercise() {
  // circle_circumference_exercise();
//  student_class_exercise();
  class_operation();
}
