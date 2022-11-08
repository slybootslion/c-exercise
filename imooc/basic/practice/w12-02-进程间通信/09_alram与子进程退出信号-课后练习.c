#include "head.h"

int count = 0;
void do_alarm02() {
  printf("warning：timeout!%d\n", count);
  count++;
  if (count == 3) {
    printf("in if\n");
    wait(NULL);
    kill(getppid(), SIGKILL);
  }
};

void alram_handle() {
  __sighandler_t sigret = signal(SIGALRM, do_alarm02);

  count = 0;
  char str[] = {0};
  char ch;
  pid_t pid = fork();
  if (pid == 0) {
    while (1) {
      alarm(3);
      pause();
      if ((ch = getchar()) != '\n') {
        printf("----x");
        strcpy(str, &ch);
      } else {
        printf("----");
        printf("input is: %s", str);
        kill(getpid(), SIGKILL);
        alram_handle();
        return;
      }
    }
  }

  if (pid > 0) {
    while (1);
  }
}
