#ifndef W13___SHMFIFO_H_
#define W13___SHMFIFO_H_

#include "sem.h"
#include "shm.h"

#define SEM_EMPTY_ID 0
#define SEM_FULL_ID 1
#define SEM_MUTEX_ID 2

typedef struct shm_head {
  int rpos; // 当前读位置
  int wpos; // 当前写位置
  int blocks; // 数据块个数
  int blksz; // 数据块大小
  int semid; // 信号量集合id
} shm_head_t;

typedef struct shm_fifo {
  shm_head_t *p_head; // 指向共享内存head区域
  char *p_payload; // 指向共享内存data区域
} shm_fifo_t;

// 创建环形队列,初始化
extern shm_fifo_t *shmfifo_init(int blocks, int blksz);
extern void shmfifo_destroy(shm_fifo_t *fifo);
extern void shmfifo_put(shm_fifo_t *fifo, const void *buf);
extern void shmfifo_get(shm_fifo_t *fifo, void *buf);

#endif //W13___SHMFIFO_H_
