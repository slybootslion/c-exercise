#include "thread_pool.h"
#include <unistd.h>

void taskfunc(void *arg) {
  int num = *(int *) arg;
  printf("task thread %ld is working, number = %d\n", pthread_self(), num);
  sleep(2);
}

int main(void) {
  tpool_t *pool = thread_pool_init(20, 100);
  int *p = NULL;
  for (int i = 0; i < 100; i++) {
    p = (int *) malloc(sizeof(int));
    *p = i + 100;
    thread_pool_add_task(pool, taskfunc, p);
  }
  while (1) {}
  sleep(30);
  thread_pool_destroy(pool);
  return 0;
}
