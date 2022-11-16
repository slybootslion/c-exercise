#include "head.h"

#define MAXEVENTS 10

void epoll_io_exec() {
  int epfd, ret;
  struct epoll_event ev;
  struct epoll_event ret_ev[MAXEVENTS];

  epfd = epoll_create(1);
  if (epfd == -1) {
    perror("[ERROR]epoll_create(): ");
  }

  printf("epfd = %d\n", epfd);

  ev.data.fd = 0;
  ev.events = EPOLLIN;
  ret = epoll_ctl(epfd, EPOLL_CTL_ADD, 0, &ev);
  if (ret == -1) {
    perror("[ERROR] epoll_ctl(): ");
    exit(EXIT_FAILURE);
  }

  for (;;) {
    ret = epoll_wait(epfd, ret_ev, MAXEVENTS, 1000);
    if (ret == -1) {
      perror("[ERROR] epoll_wait(): ");
      exit(EXIT_FAILURE);
    } else if (ret == 0) {
      printf("timeout\n");
    } else if (ret > 0) {
      char buffer[64] = {0};
      for (int i = 0; i < ret; ++i) {
        if (ret_ev[i].data.fd == 0) {
          fgets(buffer, sizeof(buffer), stdin);
          buffer[strlen(buffer) - 1] = '\0';
          if (strcmp(buffer, "quit") == 0)
            return;
          printf("buffer: %s\n", buffer);
        }
      }
    }
  }
}
