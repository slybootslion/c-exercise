#include <iostream>

using namespace std;

int main () {
	int data = 100;
	cout << "data is " << data << endl;
	
	char *str = "hello world";
	cout << "str is " << str << endl;	
	
	int a[] = {1, 2, 3, 4, 5, 6, 7};
	int len = sizeof(a)/sizeof(a[0]);
	for (int i = 0; i < len; i++)
		cout << "a["<< i <<"] is " << a[i] << endl;
}
