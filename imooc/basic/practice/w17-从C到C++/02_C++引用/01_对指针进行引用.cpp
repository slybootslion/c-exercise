#include <iostream>

using namespace std;

int main (void) {
    int data = 10;
    int* ptr = &data;
    int* &new_ptr = ptr;

    cout << *ptr << " " << *new_ptr << endl;

    return 0;
}
