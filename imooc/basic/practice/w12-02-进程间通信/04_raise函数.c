#include "head.h"

void test01() {
  pid_t cpid = fork();
  if (cpid < 0) {
    perror("[ERROR] fork(): \n");
    exit(EXIT_FAILURE);
  }

  if (cpid == 0) {
    fprintf(stdout, "\tchild %d running.\n", getpid());
    raise(SIGSTOP);
    fprintf(stdout, "\t child %d exit \n", getpid());
    exit(EXIT_SUCCESS);
  } else if (cpid > 0) {
    sleep(3);
    int ret = kill(cpid, SIGKILL);
    if (ret == 0)
      fprintf(stdout, "father %d killed child %d\n", getpid(), cpid);
    waitpid(cpid, NULL, 0); // 阻塞等待子进程退出
    fprintf(stdout, "father %d exit\n", getpid());
    exit(EXIT_SUCCESS);
  }
}
