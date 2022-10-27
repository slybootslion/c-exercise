#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
  pid_t cpid;

  cpid = fork();
  if (cpid == -1) {
    perror("[ERROR] fork()\n");
    exit(EXIT_FAILURE);
  } else if (cpid == 0) {
    perror("child process task.\n");
    exit(EXIT_SUCCESS);
  } else if (cpid > 0) {
    printf("parent process task.\n");
  }

  printf("child and process task. \n");

  return 0;
}
