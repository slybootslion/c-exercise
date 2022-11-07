#include "head.h"

void test02() {
  pid_t cpid = fork();
  if (cpid == -1) {
    perror("[ERROR] fork()");
    exit(EXIT_FAILURE);
  }
  if (cpid == 0) {
    fprintf(stdout, "child process start.\n");
    sleep(3);
    kill(getppid(), SIGUSR1);
    exit(EXIT_SUCCESS);
  } else if (cpid > 0) {
    sleep(1);
    fprintf(stdout, "main process start...\n");
    pause();
    fprintf(stdout, "main process end.\n"); // 不会打印SIGUSR1信号的默认动作是终止进程
  }
}
