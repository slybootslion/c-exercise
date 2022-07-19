#include <stdio.h>

int main()
{
  int integerType;
  float floatType;
  double doubleType;
  char charType;

  long b;
  long long c;
  long double f;

  printf("size fo int: %ld bytes\n", sizeof(integerType));
  printf("size fo float: %ld bytes\n", sizeof(floatType));
  printf("size fo double: %ld bytes\n", sizeof(doubleType));
  printf("size fo char: %ld bytes\n", sizeof(charType));

  printf("size fo long: %ld bytes\n", sizeof(b));
  printf("size fo long long: %ld bytes\n", sizeof(c));
  printf("size fo long double: %ld bytes\n", sizeof(f));

  return 0;
}
