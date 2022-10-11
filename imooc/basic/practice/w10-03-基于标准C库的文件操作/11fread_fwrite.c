//
// Created by SlybootsLion on 2022/10/11.
//
#include <stdio.h>

int main(int argc, char *argv[]) {

  FILE *fp = NULL;
  float numbers[5] = {1.1, 1.2, 1.3, 1.4, 1.5};
  float result[5] = {0};

  size_t witems = 0, ritems = 0;

  if (argc != 2) {
    fprintf(stderr, "Usage : %s <pathname> \n", argv[0]);
    return -1;
  }

  fp = fopen(argv[1], "w+");

  if (fp == NULL) {
    perror("Error fopen(): ");
    return -1;
  }

  witems = fwrite(numbers, sizeof(float), 5, fp);
  if (witems != 5) {
    perror("Error fwrite(): ");
    return -1;
  }

  // 文件定位
  fseek(fp, 0, SEEK_SET);

  ritems = fread(result, sizeof(float), 5, fp);
  if (ritems != 5) {
    perror("Error fread(): ");
    return -1;
  }

  for (int i = 0; i < 5; ++i)
    printf(" %f ", result[i]);
  putchar('\n');

  fclose(fp);

  return 0;
}
