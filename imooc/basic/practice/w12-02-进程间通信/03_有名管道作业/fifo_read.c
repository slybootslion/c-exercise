#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#define FIFO_NAME "./fifo"

void main() {
  int fd;
  char read_str[64];

  fd = open(FIFO_NAME, O_RDWR);
  if (fd == -1) {
    perror("[ERROR] open(): ");
    exit(EXIT_FAILURE);
  }

  int rbytes = read(fd, read_str, sizeof(read_str));
  if (rbytes > 0)
    printf("当前时间: %s\n", read_str);

  close(fd);
}
