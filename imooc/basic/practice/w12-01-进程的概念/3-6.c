#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <wait.h>
int main() {
  pid_t cpid;
  cpid = fork();
  if (cpid == -1) {
    perror("fork(): ");
    exit(EXIT_FAILURE);
  } else if (cpid == 0) {
    printf("the child process <%d> running... \n", getpid());
    sleep(3);
    exit(88);
  } else if (cpid > 0) {
    int rpid, status = 0;
    rpid = wait(&status);
    if (rpid == -1) {
      perror("[ERROR]wait(): ");
      exit(EXIT_FAILURE);
    }
    printf("the child process <%d> has exited, exit code <%d>.\n", rpid, WEXITSTATUS(status));
  }
  return 0;
}
