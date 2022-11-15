#include "head.h"

void poll_io_exec() {
  int ret, maxfd = 0;
  struct pollfd pfds;
  char buffer[64] = {0};
  pfds.fd = 0;
  pfds.events = POLLIN;

  for (;;) {
    ret = poll(&pfds, 1, 5000);
    if (ret == -1) {
      perror("[ERROR] poll(): ");
      exit(EXIT_FAILURE);
    } else if (ret == 0) {
      printf("timeout\n");
    } else if (ret > 0) {
      if (pfds.revents & POLLIN) {
        fgets(buffer, sizeof(buffer), stdin);
        buffer[strlen(buffer) - 1] = '\0';
        if (strcmp(buffer, "quit") == 0)
          break;
        printf("buffer: %s\n", buffer);
      }
    }
  }
}
