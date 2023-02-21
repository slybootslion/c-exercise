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

		int getlen() const {
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

	// CPP42 友元全局函数
	class Person3
	{
		friend void showAge(Person3& p);

	public:
		explicit Person3(int age) {
			this->age = age;
		}

	private:
		int age;
	};

	void showAge(Person3& p) {
		cout << p.age << endl;
	}

	void cpp42() {
		Person3 p(10);
		showAge(p);
	}

	// CPP63 友元类
	class Phone
	{
		friend class MyPhone;

	private:
		int price;
	public:
		explicit Phone(int x) {
			price = x;
		}
	};

	class MyPhone
	{
	private:
		Phone phone;
	public:
		explicit MyPhone(int x) : phone(x) {
		}

		[[nodiscard]] int get_price() const {
			return phone.price;
		}
	};

	void cpp63() {
		int p;
		cin >> p;
		MyPhone a(p);
		cout << a.get_price();
	}

	// CPP43 加号运算符重载
	class Time
	{

	public:
		int hours;      // 小时
		int minutes;    // 分钟

		Time() {
			hours = 0;
			minutes = 0;
		}

		Time(int h, int m) {
			this->hours = h;
			this->minutes = m;
		}

		void show() const {
			cout << hours << " " << minutes << endl;
		}

		Time operator+(Time& t) const {
			Time res;
			res.hours = hours + t.hours + (minutes + t.minutes) / 60;
			res.minutes = (minutes + t.minutes) % 60;
			return res;
		}

		bool operator<(Time& t) const {
			if (hours < t.hours) return true;
			if (hours > t.hours) return false;
			return minutes < t.minutes;
		}

	};

	void cpp43() {
		int h, m;
		cin >> h;
		cin >> m;

		Time t1(h, m);
		Time t2(2, 20);

		Time t3 = t1 + t2;
		t3.show();
	}

	// CPP64 重载小于号
	void cpp64() {
		int h, m;
		cin >> h;
		cin >> m;

		Time t1(h, m);
		Time t2(6, 6);

		if (t1 < t2) cout << "yes";
		else cout << "no";
	}

	// CPP44 子类中调用父类构造
	class Base
	{

	private:
		int x;
		int y;

	public:
		Base(int x, int y) {
			this->x = x;
			this->y = y;
		}

		[[nodiscard]] int getX() const {
			return x;
		}

		[[nodiscard]] int getY() const {
			return y;
		}

	};

	class Sub : public Base
	{

	private:
		int z;

	public:
		Sub(int x, int y, int z) : Base(x, y) {
			this->z = z;
		}

		[[nodiscard]] int getZ() const {
			return z;
		}

		int calculate() {
			return Base::getX() * Base::getY() * this->getZ();
		}

	};

	void cpp44() {
		int x, y, z;
		cin >> x;
		cin >> y;
		cin >> z;
		Sub sub(x, y, z);
		cout << sub.calculate() << endl;
	}

	// CPP45 重写子类计算逻辑
	class Base2
	{

	private:
		int x;
		int y;

	public:
		Base2(int x, int y) {
			this->x = x;
			this->y = y;
		}

		[[nodiscard]] int getX() const {
			return x;
		}

		[[nodiscard]] int getY() const {
			return y;
		}

		void calculate() const {
			cout << getX() * getY() << endl;
		}

	};

	class Sub2 : public Base2
	{
// write your code here......
	public:
		Sub2(int x, int y) : Base2(x, y) {
		}

		void calculate() {
			if (getY() == 0) {
				cout << "Error" << endl;
				return;
			}
			cout << getX() / getY();
		}
	};

	void cpp45() {
		int x, y, z;
		cin >> x;
		cin >> y;
		Sub2 sub(x, y);
		sub.calculate();
	}

	// CPP65 构建长方体类
	class rectangle3
	{
	private:
		int length, width;
	public:
		rectangle3(int x, int y) {
			length = x;
			width = y;
		}

		void set(int x, int y) {
			length = x;
			width = y;
		}

		[[nodiscard]] int getlength() const {
			return length;
		}

		[[nodiscard]] int getwidth() const {
			return width;
		}

		virtual int area() {
			return length * width;
		}

		[[nodiscard]] virtual int getval() const {
			return length * width;
		}
	};

	class cuboid : public rectangle3
	{
	private:
		int height;
	public:
		cuboid(int x, int y, int z) : rectangle3(x, y) {
			height = z;
		}

		int getvolume() {
			return area() * height;
		}

		int area() override {
			return rectangle3::area() * 2 + getwidth() * height * 2 + getlength() * height * 2;
		}

		[[nodiscard]] int getval () const override {
			return rectangle3::getval() * height;
		}
	};

	void cpp65() {
		int x, y, z;
		cin >> x >> y >> z;
		cuboid a(x, y, z);
		cout << a.getvolume();
	}

	// CPP66 求长方体表面积
	void cpp66() {
		int x, y, z;
		cin >> x >> y >> z;
		cuboid a(x, y, z);
		cout << a.rectangle3::area() << '\n' << a.area();
	}

	// CPP46 多态实现计算器功能
	class BaseCalculator
	{
	public:
		int m_A{};
		int m_B{};

		// write your code here......
		virtual int getResult() = 0;
	};

// 加法计算器类
	class AddCalculator : public BaseCalculator
	{
		// write your code here......
	public:
		int getResult() override {
			return m_A + m_B;
		}
	};

// 减法计算器类
	class SubCalculator : public BaseCalculator
	{
		// write your code here......
	public:
		int getResult() override {
			return m_A - m_B;
		}
	};

	void cpp46() {
		BaseCalculator* cal = new AddCalculator;
		cal->m_A = 10;
		cal->m_B = 20;
		cout << cal->getResult() << endl;
		delete cal;

		cal = new SubCalculator;
		cal->m_A = 20;
		cal->m_B = 10;
		cout << cal->getResult() << endl;
		delete cal;
	}

	// CPP67 多态实现求面积体积
	void cpp67() {
		int x, y, z;
		cin >> x >> y >> z;
		cuboid a(x, y, z);
		rectangle3 b(x, y);

		rectangle3* p = &b;
		cout << p->getval() << '\n';

		p = &a;
		cout << p->getval();
	}

	void main() {
//		cpp38();
//		cpp39();
//		cpp59();
//		cpp60();
//		cpp40();
//		cpp61();
//		cpp41();
//		cpp62();
//		cpp42();
//		cpp63();
//		cpp43();
//		cpp44();
//		cpp64();
//		cpp44();
//		cpp45();
//		cpp65();
//		cpp66();
//		cpp46();
		cpp67();

	}
}
