#include "head.h"

void do_sig_usr_(int sig) {
  printf("Receive %s \n", strsignal(sig));
}

void signal_handle() {
  if (signal(SIGUSR2, do_sig_usr_) == SIG_ERR) {
    perror("[ERROR] signal() ");
    exit(EXIT_FAILURE);
  }
  pid_t p1 = fork();
  if (p1 == 0) {
    printf("Child1 process < %d > start.\n", getpid());
    pause();
  } else if (p1 > 0) {
    sleep(1);
    int ret = kill(p1, SIGUSR1);
    if (ret == 0)
      fprintf(stdout, "father %d killed child %d\n", getpid(), p1);
    wait(NULL);

    pid_t p2 = fork();
    if (p2 == 0) {
      printf("Child2 process < %d > start.\n", getpid());
      pause();
      printf("Child2 process < %d > end.\n", getpid());
      exit(EXIT_SUCCESS);
    } else if (p2 > 0) {
      sleep(1);
      kill(p2, SIGUSR2);
      wait(NULL);
    }
  }
}
