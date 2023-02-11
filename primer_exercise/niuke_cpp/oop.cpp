#include "oop.h"

#include <utility>

namespace oop
{
	// CPP38 设计立方体类
	class Cube
	{
	public:
		void setLength(const int num) {
			length = num;
		}

		void setWidth(const int num) {
			width = num;
		}

		void setHeight(const int num) {
			height = num;
		}

		int getLength() const {
			return length;
		}

		int getWidth() const {
			return width;
		}

		int getHeight() const {
			return height;
		}

		int getArea() const {
			return 2 * (width * height + length * width + height * length);
		}

		int getVolume() const {
			return height * width * length;
		}

	private:
		int length;
		int width;
		int height;
	};

	void cpp38() {
		int length, width, height;
		cin >> length;
		cin >> width;
		cin >> height;

		Cube c{};
		c.setLength(length);
		c.setWidth(width);
		c.setHeight(height);

		cout << c.getLength() << " "
			 << c.getWidth() << " "
			 << c.getHeight() << " "
			 << c.getArea() << " "
			 << c.getVolume() << endl;
	}

	// CPP39 点和圆的关系
	// 点类
	class Pointer
	{

	private:
		int x;  // x 坐标
		int y;  // y 坐标

	public:
		void setX(int x) {
			this->x = x;
		}

		int getX() {
			return x;
		}

		void setY(int y) {
			this->y = y;
		}

		int getY() {
			return y;
		}

	};

// 圆类
	class Circle
	{

	private:
		Pointer center; // 圆心
		int radius; // 半径

	public:
		void setCenter(int x, int y) {
			center.setX(x);
			center.setY(y);
		}

		void setRadius(int radius) {
			this->radius = radius;
		}

		void isPointerInCircle(Pointer& p) {
			int px = p.getX(), py = p.getY(), cx = center.getX(), cy = center.getY();
			double direction = sqrt(pow(px - cx, 2) + pow(py - cy, 2));
			if (direction == radius) cout << "on" << endl;
			else if (direction < radius) cout << "in" << endl;
			else cout << "out" << endl;
		}

	};

	void cpp39() {
		// 键盘输入点的坐标
		int x, y;
		cin >> x;
		cin >> y;

		// 创建一个点
		Pointer p;
		p.setX(x);
		p.setY(y);

		// 创建一个圆
		Circle c;
		c.setCenter(5, 0);
		c.setRadius(5);

		// 判断点和圆的关系
		c.isPointerInCircle(p);
	}

	// CPP59 比较长方形的面积大小
	class rectangle
	{
	private:
		int length, width;
	public:
		void set(int x, int y) {
			length = x;
			width = y;
		}

		int getlength() const {
			return length;
		}

		int getwidth() const {
			return width;
		}

		int area() const {
			return length * width;
		}

		void compare(rectangle a) const {
			int self_area = area();
			int a_area = a.area();
			self_area > a_area ? cout << 1 : cout << 0;
		}
	};

	void cpp59() {
		int l1, w1, l2, w2;
		cin >> l1 >> w1 >> l2 >> w2;
		rectangle a{}, b{};
		a.set(l1, w1);
		b.set(l2, w2);
		a.compare(b);
	}

	// CPP60 长方形的关系
	class rectangle2
	{
	private:
		int length, width;
	public:
		void set(int x, int y) {
			length = x;
			width = y;
		}

		int getlength() {
			return length;
		}

		int getwidth() {
			return width;
		}

		int area() {
			return length * width;
		}

		string cancover(rectangle2& a) {
			int self_area = area();
			int a_area = a.area();
			return self_area >= a_area ? "yes" : "no";
		}
	};

	void cpp60() {
		int l1, w1, l2, w2;
		cin >> l1 >> w1 >> l2 >> w2;
		rectangle2 a, b;
		a.set(l1, w1);
		b.set(l2, w2);
		cout << a.cancover(b);
	}

	//  CPP40 构造函数
	class Person
	{
	public:
		string name;    // 姓名
		int age;    // 年龄
		Person(string name, int age) : name(std::move(name)), age(age) {
		}

		void showPerson() const {
			cout << name << " " << age << endl;
		}
	};

	void cpp40() {
		string name;
		int age;
		cin >> name;
		cin >> age;
		Person p(name, age);
		p.showPerson();
	}

	// CPP61 数组类的构造函数
	class Array
	{
	private:
		int n;//数组大小
		int* a;//数组
	public:
		Array() {
			cin >> n;
			a = new int[n];
			for (int i = 0; i < n; i++)
				cin >> a[i];
		}

		~Array() {
			delete[]a;
		}

		void show() {
			for (int i = 0; i < n; i++) cout << a[i] << ' ';
		}
	};

	void cpp61() {
		Array a;
		a.show();
	}

	// CPP41 浅拷贝和深拷贝
	class Person2
	{

	public:
		char* name; // 姓名
		int age;    // 年龄

		Person2(const char* name, int age) {
			this->name = new char[strlen(name) + 1];
			strcpy(this->name, name);
			this->age = age;
		}

		// write your code here......
		Person2(Person2& p) {
			name = new char[strlen(p.name) + 1];
			strcpy(name, p.name);
			age = p.age;
		}


		void showPerson() {
			cout << name << " " << age << endl;
		}

		~Person2() {
			if (name != nullptr) {
				delete[] name;
				name = nullptr;
			}
		}

	};

	void cpp41() {
		char name[100] = { 0 };
		int age;
		cin >> name;
		cin >> age;
		Person2 p1(name, age);
		Person2 p2 = p1;
		p2.showPerson();
	}

	// CPP62 数组类的拷贝构造函数
	class Array2
	{
	private:
		int n{};//数组大小
		int* a;//数组
	public:
		Array2() {
			cin >> n;
			a = new int[n];
			for (int i = 0; i < n; i++) cin >> a[i];
		}

		~Array2() {
			delete[]a;
		}

		Array2(Array2& arr) {
			n = arr.n;
			a = new int[n];
			for (int i = 0; i < n; i++)
				a[i] = arr.a[i];
		}

		int getlen() {
			return n;
		}

		int get(int i) {
			return a[i];
		}

		void show() {
			for (int i = 0; i < n; i++) cout << a[i] << ' ';
		}
	};

	void cpp62() {
		Array2 a;
		Array2 b = a;
		b.show();
	}

	void main() {
//		cpp38();
//		cpp39();
//		cpp59();
//		cpp60();
//		cpp40();
//		cpp61();
//		cpp41();
		cpp62();

	}
}
