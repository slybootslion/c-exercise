#include "head.h"
#define MAX_SZ 12
namespace print_mi {
void show() {
  fprintf(stderr, "\033[2J"); // 清屏
  for (int i = 0; i < MAX_SZ; ++i) {
	for (int j = 0; j < MAX_SZ; ++j) {
	  if (i == j) {
		::fprintf(stderr, "\033[%d;%dH\033[41;37m*\033[0m\n", i, j);
	  }
	  if (i == 6) {
		::fprintf(stderr, "\033[%d;%dH\033[42;37m*\033[0m\n", i, j);
	  }
	  if (j == 6) {
		::fprintf(stderr, "\033[%d;%dH\033[43;37m*\033[0m\n", i, j);
	  }
	  if (i + j == MAX_SZ) {
		::fprintf(stderr, "\033[%d;%dH\033[44;37m*\033[0m\n", i, j);
	  }
	}
  }
}
}
