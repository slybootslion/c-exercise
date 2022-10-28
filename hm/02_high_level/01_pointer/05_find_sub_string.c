#include "head.h"

int substr_handler(char *str, char *substr) {
  int idx = 0;
  while (*str != '\0') {
    if (*str != *substr) {
      idx++;
      str++;
      continue;
    }
    char *p1 = str;
    char *p2 = substr;
    while (*p2 != '\0') {
      if (*p1 != *p2) {
        str++;
        idx++;
        break;
      }
      p1++;
      p2++;
    }
    if (*p2 == '\0')
      return idx;
  }
  return -1;
}

void find_sub_string() {
  char str[] = "abcwdefwowskjdf";
  char sub_str[] = "wow";

  int idx = substr_handler(str, sub_str);
  idx >= 0 ? printf("字符串位置：%d\n", idx) : printf("未找到子串\n");
}
