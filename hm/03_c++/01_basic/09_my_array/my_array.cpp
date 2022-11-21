#include "my_array.h"

MyArray::MyArray() {
  this->m_capacity = 100;
  this->m_size = 0;
  this->p_address = new int[this->m_capacity];
}

MyArray::MyArray(int capacity) {
  this->m_capacity = capacity;
  this->m_size = 0;
  this->p_address = new int[this->m_capacity];
}

void MyArray::set_data(int pos, int val) {
  if (pos < 0 || pos > m_capacity - 1)
	return;
  cout << "pass" << endl;
  p_address[pos] = val;
}

int MyArray::get_data(int pos) {
  return p_address[pos];
}

void MyArray::push_back(int val) {
  if (m_size >= m_capacity)
	return;
  this->p_address[m_size] = val;
  this->m_size++;
}

int MyArray::get_length() {
  return this->m_size;
}

MyArray::~MyArray() {
  delete[] this->p_address;
}
