#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char *argv[]) {
  int fd;

  if (argc != 2) {
    fprintf(stderr, "Usage : < %s > < pathname >\n", argv[0]);
    return -1;
  }

//  fd = open(argv[1], O_RDONLY);
  fd = open(argv[1], O_WRONLY | O_CREAT | O_TRUNC, 0644);

  if (fd == -1) {
    perror("Open(): ");
    return -1;
  }
  printf("fd = %d\n", fd);
  close(fd);

  return 0;
}
