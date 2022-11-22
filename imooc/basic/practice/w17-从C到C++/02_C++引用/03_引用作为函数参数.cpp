#include <iostream>
using namespace std;

void change_value (int &data) {
    data = 200;
}

int main()
{
    int data = 100;
    change_value(data);

    cout << "data: " << data << endl;
    return 0;
}
