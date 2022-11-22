#include "space.h"

using namespace std;

int main() {
  int a = 1, b = 2;
  int res_a = A_Space::calc(a, b);
  int res_b = B_Space::calc(a, b);
  cout << "res_a = " << res_a << endl;
  cout << "res_b = " << res_b << endl;
  return 0;
}
