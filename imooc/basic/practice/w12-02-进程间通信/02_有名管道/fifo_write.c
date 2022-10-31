#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define FIFO_NAME "./fifo"

void main() {
  int fd;
  char wbuffer[64] = "fifo pipe.";

  int ret;
  ret = access(FIFO_NAME, F_OK);
  if (ret == -1)
    mkfifo(FIFO_NAME, 0644);

  fd = open(FIFO_NAME, O_RDWR);
  if (fd == -1) {
    perror("[ERROR] open():");
    exit(EXIT_FAILURE);
  }

  int wbytes = write(fd, wbuffer, strlen(wbuffer) + 1);
  if (wbytes < 0)
    perror("write(): ");

  close(fd);
}
