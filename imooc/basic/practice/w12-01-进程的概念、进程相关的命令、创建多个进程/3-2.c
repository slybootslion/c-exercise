#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
static int idata = 200;
int main() {
  pid_t pid;
  int istack = 300;
  pid = fork();
  if (pid < 0) {
    perror("fork():");
    exit(-1);
  } else if (pid == 0) {
    idata *= 2;
    istack *= 3;
  }
  printf("%s %d %d\n", pid == 0 ? "child" : "parent", idata, istack);

  return 0;
}
