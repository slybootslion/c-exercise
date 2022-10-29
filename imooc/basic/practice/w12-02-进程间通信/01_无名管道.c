#include "head.h"

void pipe_main01() {
  int pipefd[2];

  int ret = pipe(pipefd);
  if (ret == -1) {
    perror("[ERROR] pipe(): ");
    exit(EXIT_FAILURE);
  }

  pid_t cpid = fork();
  if (cpid == -1) {
    perror("[ERROR] fork(): ");
    exit(EXIT_FAILURE);
  } else if (cpid == 0) {
    ssize_t rbytes;
    char buffer[64] = {0};
    close(pipefd[1]); // 关闭子进程写端文件描述符

    rbytes = read(pipefd[0], buffer, sizeof(buffer)); // 当管道没有数据时，会阻塞
    if (rbytes == -1) {
      perror("[ERROR] read(): ");
      close(pipefd[0]);
      exit(EXIT_FAILURE);
    }
    printf("buffer: %s\n", buffer);
    close(pipefd[0]);
  } else if (cpid > 0) {
    size_t wbytes;
    char buffer[] = "hello pipe.";
    close(pipefd[0]); // 关闭父进程读端文件描述符

    wbytes = write(pipefd[1], buffer, strlen(buffer));
    if (wbytes == -1) {
      perror("[ERROR] write(): ");
      wait(NULL);
      close(pipefd[1]);
      exit(EXIT_FAILURE);
    }
    close(pipefd[1]);
    wait(NULL);
  }
}
