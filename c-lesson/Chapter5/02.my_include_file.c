#include <stdio.h>
#include "include/factorial.h"

int main() {
  printf("10! = %d\n", Factorial(10));

  printf("10! = %d\n", FactorialByIteration(10));
  return 0;
}
