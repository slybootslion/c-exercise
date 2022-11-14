#include "head.h"

void select_io_exec() {
  int ret, maxfd = 0;
  fd_set readfds, tmpfds;
  struct timeval tv = {3, 0}, tmp_tv;
  char buffer[64] = {0};

  FD_ZERO(&readfds);
  FD_SET(0, &readfds);

  for (;;) {
    tmp_tv = tv;
    tmpfds = readfds;

    ret = select(maxfd + 1, &tmpfds, NULL, NULL, &tmp_tv);
    if (ret == -1) {
      perror("[ERROR] select(): ");
      exit(EXIT_FAILURE);
    } else if (ret == 0) {
      printf("timeout\n");
    } else if (ret > 0) {
      if (FD_ISSET(0, &tmpfds)) {
        fgets(buffer, sizeof(buffer), stdin);
        buffer[strlen(buffer) - 1] = '\0';
        if (strcmp(buffer, "quit") == 0) break;
        printf("buffer: %s\n", buffer);
      }
    }
  }
}
