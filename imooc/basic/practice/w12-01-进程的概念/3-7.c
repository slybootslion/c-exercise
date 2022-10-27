#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
  int ret;
  ret = execl("/bin/ls", "ls", "-l", NULL);
  if (ret == -1)
  {
    perror("[ERROR]execl(): ");
    exit(EXIT_FAILURE);
  }
  return 0;
}
