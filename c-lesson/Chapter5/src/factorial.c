#include "../include/factorial.h"

unsigned int Factorial(unsigned int n) {
  return n == 0 ? 1 : n * Factorial(n - 1);
}

unsigned int FactorialByIteration(unsigned int n) {
  unsigned int result = 1;
  for (unsigned int i = n; i > 0; --i)
    result *= i;
  return result;
}
