#include "../head.h"

#define PATHNAME "."
#define PRO_ID 100
#define SZ 256

int main(void) {
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

  void *addr = shmat(shmid, NULL, 0);
  if (addr == (void *) -1) {
    perror("[ERROR] shmat() ");
    return -1;
  }

  char buffer[10];
  memcpy(buffer, addr, 10);

  for (int i = 0; i < 10; ++i)
    printf("%c", buffer[i]);
  putchar('\n');

  return 0;
}
