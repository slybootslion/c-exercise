#include "head.h"
// 多进程对 stdout 资源的竞争
union semun {
  int val;
  unsigned short *array;
};

// 创建信号量的集合
int sem_create(int nsems, unsigned short values[]) {
  key_t key = ftok(SEM_PATHNAME, SEM_PRO_ID);
  if (key == -1) {
    perror("[ERROR] ftok() ");
    return -1;
  }

  int semid = semget(key, nsems, IPC_CREAT | 0666);
  if (semid == -1) {
    perror("[ERROR] semget() ");
    return -1;
  }

  union semun s;
  s.array = values;

  int ret = semctl(semid, 0, SETALL, s);
  if (ret == -1) {
    perror("[ERROR] semctl() ");
    return -1;
  }

  return semid;
}

// 占用信号量资源
int sem_p(int semid, int semnum) {
  struct sembuf sops;

  sops.sem_num = semnum;
  sops.sem_op = -1;
  sops.sem_flg = SEM_UNDO;

  return semop(semid, &sops, 1);
}

// 释放信号量资源
int sem_v(int semid, int semnum) {
  struct sembuf sops;

  sops.sem_num = semnum;
  sops.sem_op = 1;
  sops.sem_flg = SEM_UNDO;

  return semop(semid, &sops, 1);
}

// 删除信号量集合
int sem_del(int semid) {
  return semctl(semid, 0, IPC_RMID, NULL);
}

void test07() {
  unsigned short values[] = {1};
  int semid = sem_create(1, values);
  if (semid == -1) {
    exit(EXIT_FAILURE);
  }

  pid_t cpid = fork();

  if (cpid == -1) {
    perror("[ERROR] fork() ");
    exit(EXIT_FAILURE);
  }

  int c = 0;
  if (cpid == 0) {
    while (++c < 10000) {
      sem_p(semid, 0);
      printf("-----------\n");
      printf("c start.\n");
      sleep(1);
      printf("c end.\n");
      sem_v(semid, 0);
    }
  }

  if (cpid > 0) {
    sleep(1);
    while (++c < 10000) {
      sem_p(semid, 0);
      printf("-----------\n");
      printf("p start.\n");
      sleep(1);
      printf("p end.\n");
      sem_v(semid, 0);
    }
    wait(NULL);
    sem_del(semid);
  }
}
