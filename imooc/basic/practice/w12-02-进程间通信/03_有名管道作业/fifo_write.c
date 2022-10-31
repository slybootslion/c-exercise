#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <time.h>

#define FIFO_NAME "./fifo"

void get_time_format(char *tmpBuf) {
  time_t t = time(0);
  strftime(tmpBuf, 64, "%Y-%m-%d %H:%M:%S", localtime(&t));
}

void main() {
  int fd;
  char time_str[64];
  get_time_format(time_str);

  int ret = access(FIFO_NAME, F_OK);
  if (ret == -1)
    mkfifo(FIFO_NAME, 0644);

  fd = open(FIFO_NAME, O_RDWR);
  if (fd == -1) {
    perror("[ERROR] open():");
    exit(EXIT_FAILURE);
  }

  int wbytes = write(fd, time_str, strlen(time_str) + 1);
  if (wbytes < 0)
    perror("write(): ");

  close(fd);
}
