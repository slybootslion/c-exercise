#ifndef INC_01_BASIC_09_MY_ARRAY_MY_ARRAY_H_
#define INC_01_BASIC_09_MY_ARRAY_MY_ARRAY_H_

#include <iostream>
using namespace std;

class MyArray {
  private:
	int m_capacity;
	int m_size;
	int *p_address;
  public:
	MyArray();
	explicit MyArray(int capacity);
	void set_data(int pos, int val);
	int get_data(int pos);
	void push_back(int val);
	int get_length();
	~MyArray();
};

#endif //INC_01_BASIC_09_MY_ARRAY_MY_ARRAY_H_
