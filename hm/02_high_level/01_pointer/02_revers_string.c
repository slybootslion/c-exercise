#include "head.h"

void reverse_string1(char *str) {
  const unsigned long len = strlen(str);
  unsigned long start = 0, end = len - 1;
  while (start < end) {
    char temp = str[start];
    str[start] = str[end];
    str[end] = temp;
    start++;
    end--;
  }
}

void reverse_string2(char *str) {
  const unsigned long len = strlen(str);
  char *start = str, *end = str + len - 1;
  while (start < end) {
    char temp = *start;
    *start = *end;
    *end = temp;
    start++;
    end--;
  }
}
