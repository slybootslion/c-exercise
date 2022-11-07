#include "head.h"

void code_file(char *source_file, char *dest_file) {
  srand((unsigned int)time(NULL));
  FILE *file1 = fopen(source_file, "r");
  FILE *file2 = fopen(dest_file, "w");

  int ch;
  while ((ch = fgetc(file1)) != EOF) {
    short temp = (short) ch;
    temp <<= 4;
    temp |= (short) 0x8000;
    temp += (short) (rand() % 16);
    fprintf(file2, "%hd", temp);
  }

  fclose(file1);
  fclose(file2);
}

void decode_file(char *source_file, char *dest_file) {
  FILE *file1 = fopen(source_file, "r");
  FILE *file2 = fopen(dest_file, "w");

  short temp;
  while (!feof(file1)) {
    fscanf(file1, "%hd", &temp);
    temp <<= 1;
    temp >>= 5;
    char ch = (char) temp;
    fputc(ch, file2);
  }

  fclose(file1);
  fclose(file2);
}
