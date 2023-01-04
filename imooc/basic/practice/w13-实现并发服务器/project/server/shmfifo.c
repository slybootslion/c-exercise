#include <string.h>
#include "shmfifo.h"

static int g_shmid;

shm_fifo_t *shmfifo_init(int blocks, int blksz) {
  int shm_sz = 0;
  enum shm_create_status s_create_type;
  unsigned short values[] = {0, blocks, 1}; // 对3个信号量进行初始化
  shm_fifo_t *p_shm_fifo = (shm_fifo_t *) malloc(sizeof(p_shm_fifo));
  if (!p_shm_fifo) return NULL;
  shm_sz = blocks * blksz + sizeof(shm_head_t); // 计算映射大小
  s_create_type = shm_create(shm_sz, &g_shmid); // 创建共享内存
  if (s_create_type != SHM_CREATE_ERROR) {
    p_shm_fifo->p_head = (shm_head_t *) shm_at(g_shmid); // 共享内存映射
    if (s_create_type == SHM_CREATE_NEW) { // 如果时新创建的共享内存，则进行初始化
      p_shm_fifo->p_head->rpos = 0; // 初始化读环队列的位置，相当于出队列的位置
      p_shm_fifo->p_head->wpos = 0; // 初始化写环队列的位置，相当于入队列的位置
      p_shm_fifo->p_head->blocks = blocks; // 初始化block的数量
      p_shm_fifo->p_head->blksz = blksz; // 初始化每个block的大小
      p_shm_fifo->p_head->semid = sem_create(3, values); // 创建信号量合集，包含3个信号量
    }
    // 计算数据的起始位置，并保存到payload指针中
    p_shm_fifo->p_payload = (char *) (p_shm_fifo->p_head + 1);
    return p_shm_fifo;
  }
  return NULL;
}

void shmfifo_destroy(shm_fifo_t *fifo) {
  sem_del(fifo->p_head->semid); // 删除信号量集和
  shm_dt(fifo->p_head); // 解除共享内存映射
  shm_del(g_shmid); // 删除共享内存
  free(fifo); // 释放环形队列结构体对象
}

void shmfifo_put(shm_fifo_t *fifo, const void *buf) {
  int pos = 0;
  sem_p(fifo->p_head->semid, SEM_FULL_ID); // 占用判满的信号量
  sem_p(fifo->p_head->semid, SEM_MUTEX_ID);
  pos = fifo->p_head->wpos * fifo->p_head->blksz; // 计算偏移量
  memcpy(fifo->p_payload + pos, buf, fifo->p_head->blksz); // 拷贝数据到环形队列中
  fifo->p_head->wpos = (fifo->p_head->wpos + 1) % fifo->p_head->blocks; // 更新偏移量
  sem_v(fifo->p_head->semid, SEM_MUTEX_ID);
  sem_v(fifo->p_head->semid, SEM_EMPTY_ID);
}

void shmfifo_get(shm_fifo_t *fifo, void *buf) {
  int pos = 0;
  sem_p(fifo->p_head->semid, SEM_EMPTY_ID);
  sem_p(fifo->p_head->semid, SEM_MUTEX_ID);
  pos = fifo->p_head->rpos * fifo->p_head->blksz;
  memcpy(buf, fifo->p_payload + pos, fifo->p_head->blksz);
  fifo->p_head->rpos = (fifo->p_head->rpos + 1) % fifo->p_head->blocks;
  sem_v(fifo->p_head->semid, SEM_MUTEX_ID);
  sem_v(fifo->p_head->semid, SEM_FULL_ID);
}
