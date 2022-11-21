#include "my_array.h"

void test_my_array() {
  MyArray my_array(50);
  for (int i = 0; i < 50; ++i) {
	my_array.push_back(i + 1);
//	my_array.set_data(i, i + 1);
  }
  for (int i = 0; i < my_array.get_length(); ++i)
	cout << my_array.get_data(i) << " ";
  cout << endl;
}
