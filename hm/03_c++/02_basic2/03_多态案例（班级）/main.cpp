#include <iostream>
using namespace std;

// 学生
class Manito {
  public:
	virtual void show() = 0;
};

class Maker : public Manito {
  public:
	Maker(string name, int age, string sex, string Skill) {
	  this->age = age;
	  this->name = name;
	  this->sex = sex;
	  this->Skill = Skill;
	}
	virtual void show() {
	  cout << name << "展现" << Skill << endl;
	}
  private:
	string name;
	int age;
	string sex;
	string Skill;
};

// 班级
class MyClass {
  public:
	MyClass() {
	  m_capacity = 50;
	  m_size = 0;
	  this->p = new Manito *[m_capacity];
	}
	void add_manito(Manito *m) {
	  if (m_size == m_capacity) return;
	  this->p[m_size] = m;
	  m_size++;
	}
	void start_show() {
	  for (int i = 0; i < m_size; ++i)
		p[i]->show();
	}
	~MyClass() {
	  for (int i = 0; i < m_size; ++i) {
		if (p[i] != nullptr) {
		  delete p[i];
		  p[i] = nullptr;
		}
	  }
	  delete[] p;
	  p = nullptr;
	}
  private:
	Manito **p;
	int m_size;
	int m_capacity;
};

void test() {
  MyClass *mc = new MyClass;
  mc->add_manito(new Maker("student1", 19, "male", "dance"));
  mc->add_manito(new Maker("student2", 18, "female", "sing"));
  mc->start_show();
  delete mc;
}

int main() {
  test();
  return 0;
}
