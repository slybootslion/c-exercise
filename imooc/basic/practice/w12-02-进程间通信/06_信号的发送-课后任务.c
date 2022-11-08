#include "head.h"

void signal_sending() {
  pid_t p1 = fork();
  if (p1 == 0) {
    fprintf(stdout, "\tchild %d running.\n", getpid());
    raise(SIGSTOP);
  }
  if (p1 > 0) {
    sleep(1);
    int ret = kill(p1, SIGKILL);
    if (ret == 0)
      fprintf(stdout, "father %d killed child %d\n", getpid(), p1);
    waitpid(p1, NULL, 0);
    pid_t p2 = fork();
    if (p2 == 0) {
      fprintf(stdout, "\tchild %d running.\n", getpid());
      raise(SIGSTOP);
    }
    if (p2 > 0) {
      sleep(1);
      int ret = kill(p2, SIGKILL);
      if (ret == 0)
        fprintf(stdout, "father %d killed child %d\n", getpid(), p2);
      waitpid(p2, NULL, 0);
      fprintf(stdout, "father %d exit\n", getpid());
    }
  }
}
