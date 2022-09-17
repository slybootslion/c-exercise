#include <stdio.h>

unsigned int Factorial(unsigned int n) {
  return n == 0 ? 1 : n * Factorial(n - 1);
}

unsigned int FactorialByIteration(unsigned int n) {
  unsigned int result = 1;
  for (unsigned int i = n; i > 0; --i)
    result *= i;
  return result;
}

unsigned int Fibonacci(unsigned int n) {
  if (n == 1 || n == 0)
    return n;
  else
    return Fibonacci(n - 1) + Fibonacci(n - 2);
}

unsigned int FibonacciByIteration(unsigned int n) {
  if (n == 1 || n == 0)
    return n;
  unsigned int current = 1;
  unsigned int last = 0;
  for (int i = 0; i < n - 1; ++i) {
    unsigned temp = current;
    current += last;
    last = temp;
  }
  return current;
}

int main() {
  printf("3! = %d\n", Factorial(3));
  printf("5! = %d\n", Factorial(5));
  printf("10! = %d\n", Factorial(10));

  printf("3! = %d\n", FactorialByIteration(3));
  printf("5! = %d\n", FactorialByIteration(5));
  printf("10! = %d\n", FactorialByIteration(10));

  printf("Fibonacci(3) = %d\n", Fibonacci(3));
  printf("Fibonacci(5) = %d\n", Fibonacci(5));
  printf("Fibonacci(10) = %d\n", Fibonacci(10));

  printf("Fibonacci(3) = %d\n", FibonacciByIteration(3));
  printf("Fibonacci(5) = %d\n", FibonacciByIteration(5));
  printf("Fibonacci(10) = %d\n", FibonacciByIteration(10));
  return 0;
}
