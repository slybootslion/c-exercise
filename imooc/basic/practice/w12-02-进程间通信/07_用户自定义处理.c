#include "head.h"

void do_sig_usr(int sig) {
  printf("Receive %s \n", strsignal(sig));
}

void test03() {
  if (signal(SIGUSR1, do_sig_usr) == SIG_ERR) {
    perror("[ERROR] signal(): ");
    exit(EXIT_FAILURE);
  }

  pid_t cpid = fork();
  if (cpid == -1) {
    perror("fork(): ");
    exit(EXIT_FAILURE);
  } else if (cpid == 0) {
    printf("Child process < %d > start.\n", getpid());
    pause();
    printf("Child process < %d > end.\n", getpid());
    exit(EXIT_SUCCESS);
  } else if (cpid > 0) {
    sleep(1);
    kill(cpid, SIGUSR1);
    wait(NULL);
  }
}
