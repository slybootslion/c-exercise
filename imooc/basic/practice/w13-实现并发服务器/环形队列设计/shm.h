#ifndef W13___SHM_H_
#define W13___SHM_H_

#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>

/*
 * SHM_HAS_EXIST：共享内存已经存在
 * SHM_CREATE_NEW：共享内存为新创建
 * SHM_CREATE_ERROR：共享内存创建错误
 * 用途：用于后续环形队列区分是否为第一次创建，在第一次创建时会进行初始化，否则不用
 * */
enum shm_create_status {
  SHM_HAS_EXIST = 0,
  SHM_CREATE_NEW,
  SHM_CREATE_ERROR,
};

extern enum shm_create_status shm_create(size_t size, int *pshmid); // 创建共享内存
extern void *shm_at(int shmid); // 映射
extern int shm_dt(const void *shmaddr); // 解除映射
extern int shm_del(int shmid); // 删除共享内存

#endif //W13___SHM_H_
