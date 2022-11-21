#include "head.h"

namespace N07 {
class Person {
  public:
	string name;
	int age;
  public:
	Person(string name, int age) {
	  this->name = name;
	  this->age = age;
	}
	Person PersonPlusPerson(Person &person) {
	  string new_name = this->name + person.name;
	  int new_age = this->age + person.age;
	  Person new_person(new_name, new_age);
	  return new_person;
	}
	void show_person() {
	  cout << "name: " << name << " age: " << age << endl;
	}
};

Person PersonPlusPerson(Person &p1, Person &p2) {
  string new_name = p1.name + p2.name;
  int new_age = p1.age + p2.age;
  Person new_person(new_name, new_age);
  return new_person;
}

void test01() {
  Person person("John", 100);
  person.show_person();
  print_line();
  Person person_1("John", 20);
  Person person_2("001", 10);
  Person person_3 = PersonPlusPerson(person_1, person_2);
  person_1.show_person();
  person_2.show_person();
  person_3.show_person();
  Person person_4 = person_1.PersonPlusPerson(person_2);
  person_4.show_person();
}
}

void this_exercise() {
  N07::test01();
}
