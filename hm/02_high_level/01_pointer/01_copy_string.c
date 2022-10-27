//
// Created by SlybootsLion on 2022/10/27.
//
#include "head.h"

void copy_string1(char *origin, char *target) {
  unsigned long len = strlen(origin);
  for (int i = 0; i < len; ++i)
    target[i] = origin[i];
}

void copy_string2(char *origin, char *target) {
  while (*origin != '\0') {
    *target = *origin;
    origin++;
    target++;
  }
}

void copy_string3(char *origin, char *target) {
  while (*target++ = *origin++);
}
