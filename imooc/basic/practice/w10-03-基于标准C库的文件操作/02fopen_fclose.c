#include <stdio.h>

int main(int argc, char *argv[]) {
  if (argc != 2) {
    fprintf(stderr, "Usage: ./a.out <pathname>.\n");
    return -1;
  }

  FILE *fp = fopen(argv[1], "w+");

  if (NULL == fp) {
    perror("Error fopen(): \n");
    return -1;
  }

  fclose(fp);

  return 0;
}
