#include "head.h"
#define MAX_SZ 11
namespace print_mi {
// \033[44;37m
void print_method(int i, int j, const string &c) {
  const string color = "\033[%d;%dH\033[" + c + ";37m*\033[0m\n";
  cout << color.length() << endl;
  const char *str_c;
  for (int i = 0; i < color.length(); ++i) {
	cout << color[i] << endl;
  }
  fprintf(stderr, str_c, i,j);
}

void show() {
  for (int i = 0; i < MAX_SZ; ++i) {
	for (int j = 0; j < MAX_SZ; ++j) {
	  if (i == j) {
		print_method(i, j, "41");
	  }
	  if (j == 6) {
		print_method(i, j, "42");
	  }
	}
  }
}
}
