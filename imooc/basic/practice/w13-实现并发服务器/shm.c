#include "shm.h"

#define PATHNAME "."
#define PRO_ID 101

enum shm_create_status shm_create(size_t size, int *pshmid) {
  key_t key;
  int shmid;

  key = ftok(PATHNAME, PRO_ID); // 创建key
  shmid = shmget(key, size, 0); // 获取共享内存id
  if (shmid == -1) { // 返回-1则表示内存不存在，需要进行创建
    shmid = shmget(key, size, IPC_CREAT | 0644); // 创建共享内存
    if (shmid == -1) {
      perror("[ERROR] shmget(): ");
      return SHM_CREATE_ERROR; // 返回错误
    }
    *pshmid = shmid;
    return SHM_CREATE_NEW; // 返回共享内存为新创建的状态
  } else {
    *pshmid = shmid;
    return SHM_HAS_EXIST;
  }
}

void *shm_at(int shmid) {
  void *addr = NULL;
  addr = shmat(shmid, NULL, 0);
  if (addr == (void *) -1) {
    perror("[ERROR] shmat(): ");
    return NULL;
  }
  return addr;
}

int shm_dt(const void *shmaddr) {
  return shmdt(shmaddr);
}
int shm_del(int shmid) {
  return shmctl(shmid, IPC_RMID, NULL);
}
