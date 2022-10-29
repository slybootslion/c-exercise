#include <unistd.h>
#include <stdio.h>
int main() {
  pid_t cpid;
  write(STDERR_FILENO, "HELLO", 6);
  fputs("hello", stdout);
  cpid = fork();
  if (cpid == -1) {
    perror("fork():");
    return -1;
  }
  return 0;
}
