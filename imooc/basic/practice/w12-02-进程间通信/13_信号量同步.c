#include "head.h"

void test08() {
  unsigned short values[2] = {1, 0};
  int semid = sem_create(2, values);
  if (semid == -1)
    exit(EXIT_FAILURE);

  pid_t cpid = fork();
  if (cpid == -1) {
    perror("[ERROR] fork() ");
    exit(EXIT_FAILURE);
  }
  if (cpid == 0) {
    while (1) {
      sem_p(semid, SEM_CONTROL_C);
      putchar('B');
      fflush(stdout);
      sem_v(semid, SEM_CONTROL_P);
    }
  }
  if (cpid > 0) {
    while (1) {
      sem_p(semid, SEM_CONTROL_P);
      putchar('A');
      fflush(stdout);
      sem_v(semid, SEM_CONTROL_C);
      sem_p(semid, SEM_CONTROL_P);
      putchar('A');
      fflush(stdout);
      sem_v(semid, SEM_CONTROL_P);
      sleep(1);
      putchar('\n');
    }
    wait(NULL);
  }
}
