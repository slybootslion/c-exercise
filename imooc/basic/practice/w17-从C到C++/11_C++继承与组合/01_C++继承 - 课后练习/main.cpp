#include <iostream>

using namespace std;

class Hero {
  private:
	string name;
  public:
	explicit Hero(const string &name = "hero") {
	  cout << "Hero Class Constructor" << endl;
	  this->name = name;
	}
	~Hero() {
	  cout << "Hero Class Destructor" << endl;
	}
	string get_name() {
	  return this->name;
	};
};

class Shooter {
  private:
	int distance;
  public:
	explicit Shooter(int distance = 0) {
	  cout << "Shooter Class Constructor" << endl;
	  this->distance = distance;
	}
	~Shooter() {
	  cout << "Shooter Class Destructor" << endl;
	}
	int get_distance() {
	  return this->distance;
	}

};

class Houyi : public Hero, public Shooter {
  private:
	int leg_len;
  public:
	Houyi(const string &name, const int distance, const int leg_len) : Hero(name), Shooter(distance) {
	  cout << "Houyi Class Constructor" << endl;
	  this->leg_len = leg_len;
	}
	~Houyi() {
	  cout << "Houyi Class Destructor" << endl;
	}
	void show() {
	  cout << "----------------------------" << endl;
	  cout << "Hero name: " << this->get_name() << endl;
	  cout << "Hero distance: " << this->get_distance() << endl;
	  cout << "Hero leg_len: " << this->leg_len << endl;
	  cout << "----------------------------" << endl;
	}
};

int main() {
  Houyi houyi("tiedan", 100, 30);
  houyi.show();
  return 0;
}
