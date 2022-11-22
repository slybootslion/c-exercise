#include <iostream>
using namespace std;

class Clock
{
private:
    int hour;
    int minute;
    int second;

public:
    void set_hour(int num)
    {
        if (num > 24 || num < 0)
            return;
        this->hour = num;
    }
    void set_minute_second(int num, bool is_minute = true)
    {
        if (num < 0 || num > 60)
            return;
        is_minute ? this->minute = num : this->second = num;
    }
    void print_clock_time() const
    {
        cout << "time: " << hour << ":" << minute << ":" << second << endl;
    }
};

int main()
{
    Clock c1; // 堆栈
    c1.set_hour(10);
    c1.set_minute_second(33);
    c1.set_minute_second(45, false);
    c1.print_clock_time();

    static Clock c2; // 静态区
    c2.set_hour(11);
    c2.set_minute_second(34);
    c2.set_minute_second(46, false);
    c2.print_clock_time();

    // 堆区
    Clock *c3 = new Clock;
    c3->set_hour(12);
    c3->set_minute_second(35);
    c3->set_minute_second(47, false);
    c3->print_clock_time();
    delete c3;

    return 0;
}
