#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  FILE *fp = NULL;
  int numa = 10, numb = 20, numc = 30;
  char buffer[64] = {0};

  if (argc != 2) {
    fprintf(stdout, "Usage: %s <pathname> \n", argv[0]);
    return -1;
  }

  fp = fopen(argv[1], "w+");
  if (NULL == fp) {
    perror("Error fopen(): ");
    return -1;
  }

  fprintf(fp, "%d-%d-%d", numa, numb, numc);
  sprintf(buffer, "%d-%d-%d", numa, numb, numc);

  printf("buffer: %s\n", buffer);

  fclose(fp);
  return 0;
}
