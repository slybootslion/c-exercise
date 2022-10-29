#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
int main() {
  pid_t cpid;

  cpid = fork();
  if (cpid == -1) {
    perror("fork(): ");
    exit(EXIT_FAILURE);
  } else if (cpid == 0) {
    printf("The child process <%d> running... \n", getpid());
    sleep(2);
    printf("The child process <%d> has exited.1 \n", getpid());
    exit(EXIT_SUCCESS);
  } else if (cpid > 0) {
    cpid = fork();
    if (cpid == -1) {
      perror("fork(): ");
    } else if (cpid == 0) {
      printf("The child process <%d> running... \n", getpid());
      sleep(3);
      printf("The child process <%d> has exited.2 \n", getpid());
      exit(EXIT_SUCCESS);
    } else if (cpid > 0) {

    }
  }

  return 0;
}
