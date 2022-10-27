#include <unistd.h>
#include <stdio.h>

int main() {
  pid_t cpid;
  cpid = fork();
  if (cpid == -1) {
    perror("fork():");
    return -1;
  }
  printf("hello world.\n");
  return 0;
}
