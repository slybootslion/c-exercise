#include "sem.h"

#define SEM_PATHNAME "."
#define SEM_PRO_ID 99

union semun {
  int val; // setval
  unsigned short *array; // arraya for getall/setall
};

int sem_create(int nsems, unsigned short values[]) {
  int semid, ret;
  key_t key;
  union semun s;

  key = ftok(SEM_PATHNAME, SEM_PRO_ID);
  if (key == -1) {
    perror("[ERROR] ftok(): ");
    return -1;
  }

  semid = semget(key, nsems, IPC_CREAT | 0666);
  if (semid == -1) {
    perror("[ERROR] semget(): ");
    return -1;
  }

  s.array = values;

  ret = semctl(semid, 0, SETALL, s);
  if (ret == -1) {
    perror("[ERROR] semctl(): ");
    return -1;
  }

  return semid;
}

int sem_p(int semid, int semnum) {
  struct sembuf sops;
  sops.sem_num = semnum;
  sops.sem_op = -1;
//  sops.sem_flg = SEM_UNDO;
  return semop(semid, &sops, 1);
}

int sem_v(int semid, int semnum) {
  struct sembuf sops;
  sops.sem_num = semnum;
  sops.sem_op = 1;
//  sops.sem_flg = SEM_UNDO;
  return semop(semid, &sops, 1);
}

int sem_del(int semid) {
  return semctl(semid, 0, IPC_RMID, NULL);
}
