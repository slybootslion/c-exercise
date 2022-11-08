#include "head.h"

void do_alarm(int sig) {
  printf("Receive signal < %s >\n", strsignal(sig));
}

void alarm_test01() {
  __sighandler_t sigret;
  sigret = signal(SIGALRM, do_alarm);
  if (sigret == SIG_ERR) {
    perror("[ERROR] signal() ");
    exit(EXIT_FAILURE);
  }

  alarm(3);
  pause();
}

// 子进程退出信号
void do_sig_child(int sig) {
  printf("Receive signal < %s > \n", strsignal(sig));
  wait(NULL);
}

void alarm_test02() {
  __sighandler_t sigret = signal(SIGCHLD, do_sig_child);
  if (sigret == SIG_ERR) {
    perror("[ERROR] signal() ");
    exit(EXIT_FAILURE);
  }

  pid_t cpid = fork();
  if (cpid == -1) {
    perror("[ERROR] fork(): ");
    exit(EXIT_FAILURE);
  } else if (cpid == 0) {
    printf("child process < %d > start.\n", getpid());
    sleep(2);
    exit(EXIT_SUCCESS);
  } else if (cpid > 0) {
    while (1);
  }
}

void test04() {
//  alarm_test01();
  alarm_test02();
}
