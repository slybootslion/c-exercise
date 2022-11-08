#include "head.h"

#define PATHNAME "."
#define PROID 10

void test05() {
  key_t key = ftok(PATHNAME, PROID);
  if (key == -1) {
    perror("fotk() ");
    exit(EXIT_FAILURE);
  }

  int msgid = msgget(key, IPC_CREAT | 0666);
  if (msgid == -1) {
    perror("msgget(): ");
    exit(EXIT_FAILURE);
  }

  printf("msg id: %d\n", msgid);

  int ret = msgctl(msgid, IPC_RMID, NULL);
  if (ret == -1) {
    perror("msgctl(): ");
    exit(EXIT_FAILURE);
  }
}
