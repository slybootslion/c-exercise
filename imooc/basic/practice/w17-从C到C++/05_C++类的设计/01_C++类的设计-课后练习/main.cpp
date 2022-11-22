#include <iostream>
using namespace std;

class Clock {
  private:
	int hour;
	int minute;
	int second;
  public:
	void set_hour(int num) {
	  if (num > 24 || num < 0)
		return;
	  this->hour = num;
	}
	void set_minute_second(int num, bool is_minute = true) {
	  if (num < 0 || num > 60)
		return;
	  is_minute ? this->minute = num : this->second = num;
	}
	void print_clock_time() const {
	  cout << "time: " << hour << ":" << minute << ":" << second;
	}
};

int main() {
  Clock c{};
  c.set_hour(10);
  c.set_minute_second(33);
  c.set_minute_second(45, false);
  c.print_clock_time();
  return 0;
}
