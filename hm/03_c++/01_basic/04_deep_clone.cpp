#include "head.h"

class Person {
  public:
	Person(char *name, int age) {
	  p_name = (char *)malloc(strlen(name) + 1);
	  strcpy(p_name, name);
	  m_age = age;
	}
	Person(const Person &person) {
	  p_name = (char *)malloc(strlen(person.p_name) + 1);
	  strcpy(p_name, person.p_name);
	  m_age = person.m_age;
	}
	~Person() {
	  if (p_name != NULL)
		free(p_name);
	}
  private:
	char *p_name;
	int m_age;
};

// 需要看下课程，没弄懂这个意思
void dp_test01() {
  Person p1("Edward", 30);
  Person p2 = p1;
}

void deep_clone_exercise() {
  dp_test01();
}
