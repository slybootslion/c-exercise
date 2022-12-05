#include "../head.h"
#include "./01_string.h"

namespace StringA7 {
void test01() {
  string str = "hello";
  for (int i = 0; i < str.size(); i++) {
    str[i] = toupper(str[i]);
    cout << str[i];
  }
  cout << endl;
  for (int i = 0; i < str.size(); i++) {
    str[i] = tolower(str[i]);
    cout << str[i];
  }
  cout << endl;
}
}
