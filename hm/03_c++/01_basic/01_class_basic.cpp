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

class Cub {
 private:
  int ml; // 长
  int mw; // 宽
  int mh; // 高
 public:
  void set_l(int l) {
	ml = l;
  }
  void set_w(int w) {
	mw = w;
  }
  void set_h(int h) {
	mh = h;
  }
  int get_l() {
	return ml;
  }
  int get_w() {
	return mw;
  }
  int get_h() {
	return mh;
  }
  int cube_area() {
	return (ml * mw + ml * mh + mw * mh) * 2;
  }
  int cube_volume() {
	return ml * mw * mh;
  }
  bool cub_compare(Cub &c) {
	return get_l() == c.get_l() && get_w() == c.get_w() && get_h() == c.get_h();
  }
};

bool cub_compare(Cub &c1, Cub &c2) {
  return c1.get_l() == c2.get_l() && c1.get_w() == c2.get_w() && c1.get_h() == c2.get_h();
}

void cub_exercise() {
  Cub c1, c2;

  c1.set_l(10);
  c1.set_w(20);
  c1.set_h(30);

  c2.set_l(10);
  c2.set_w(20);
  c2.set_h(30);

  cout << "c1 area:" << c1.cube_area() << " volume:" << c1.cube_volume() << endl;
  cout << "c2 area:" << c2.cube_area() << " volume:" << c2.cube_volume() << endl;

  if (cub_compare(c1, c2))
	cout << "c1 is same c2" << endl;
  else
	cout << "c1 is not same c2" << endl;

  cout << "------------------------------" << endl;

  c1.cub_compare(c2) ? cout << "c1 is same c2" << endl : cout << "c1 is not same c2" << endl;
}

class Point {
 public:
  void set_x(int x) {
	mx = x;
  }
  void set_y(int y) {
	my = y;
  }
  int get_x() {
	return mx;
  }
  int get_y() {
	return my;
  }
 private:
  int mx;
  int my;
};

class Circle_ {
 public:
  void set_p(int x, int y) {
	mp.set_x(x);
	mp.set_y(y);
  }
  void set_r(int r) {
	mr = r;
  }
  Point &get_p() {
	return mp;
  }
  int get_r() {
	return mr;
  }
  void is_point_in_circle(Point &point) {
	int distance = (point.get_x() - mp.get_x()) * (point.get_x() - mp.get_x())
		+ (point.get_y() - mp.get_y()) * (point.get_y() - mp.get_y());
	int radius = mr * mr;
	if (distance < radius)
	  cout << "point(" << point.get_x() << "," << point.get_y() << ") in circle." << endl;
	else if (distance > radius)
	  cout << "point(" << point.get_x() << "," << point.get_y() << ") out circle." << endl;
	else
	  cout << "point(" << point.get_x() << "," << point.get_y() << ") on circle." << endl;
  }
 private:
  Point mp;
  int mr;
};

void point_circle_exercise() {
  Circle_ circle;
  circle.set_p(20, 20);
  circle.set_r(5);

  Point point;
  point.set_x(25);
  point.set_y(20);

  circle.is_point_in_circle(point);
}

void class_basic_exercise() {
  // circle_circumference_exercise();
//  student_class_exercise();
//  class_operation();
//  cub_exercise();
  point_circle_exercise();
}
