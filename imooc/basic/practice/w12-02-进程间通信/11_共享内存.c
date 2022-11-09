#include "head.h"

#define PATHNAME "."
#define PRO_ID 100
#define SZ 256

void test06() {
  key_t key = ftok(PATHNAME, PRO_ID);
  if (key == -1) {
    perror("[ERROR] ftok()");
    exit(EXIT_FAILURE);
  }

  int shmid = shmget(key, SZ, IPC_CREAT | 0666);
  if (shmid == -1) {
    perror("shmid(): ");
    exit(EXIT_FAILURE);
  }

  printf("shmid = %d\n", shmid);

  int ret = shmctl(shmid, IPC_RMID, NULL);
  if (ret == -1) {
    perror("[ERROR] shmctl() ");
    exit(EXIT_FAILURE);
  }
}
