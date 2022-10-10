#include <stdio.h>
int main(int argc, char *argv[]) {
  FILE *fp = NULL;
  char ch;
  if (argc != 3) {
    fprintf(stderr, "Usage: %s <pathname> <pathname> \n", argv[0]);
    return -1;
  }

  fp = fopen(argv[1], "r");
  if (NULL == fp) {
    perror("Error fopen(): ");
    return -1;
  }

  FILE *fpw = fopen(argv[2], "w");

  for (;;) {
    ch = fgetc(fp);
    if (ch == EOF)
      break;
    fputc(ch, fpw);
  }

  fclose(fp);
  fclose(fpw);

  return 0;
}
