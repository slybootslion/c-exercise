//
// Created by SlybootsLion on 2022/10/11.
//
#include <stdio.h>

int main() {
  FILE *fpr = fopen("1-81.jpg", "r");
  FILE *fpw = fopen("copy.jpg", "w+");

  char buffer[64] = {0};
  size_t t = 0;
  while ((t = fread(buffer, sizeof buffer[0], sizeof buffer, fpr)) > 0) {
    printf("t = %zu\n", t);
    fwrite(buffer, sizeof buffer[0], t, fpw);
  }

  fclose(fpr);
  fclose(fpw);

  return 0;
}
