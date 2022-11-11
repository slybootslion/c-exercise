#include "head.h"

int main(int argc, char *argv[]) {
//  pipe_main01();
//  pipe_main02();
//  test01();
//  test02();
//  signal_sending();
//  test03();
//  signal_handle();
//  test04();
//  test05();
//  alram_handle();
//  test06();
//  test07();
//  test08();
//  sem_handle();
//  test09();
//  test10();
//  fadenkommunikation();
//  test11(argc, argv);
  return 0;
}


// 1-2 线程互斥锁-课后任务
/*static int global = 0;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void *do_thread(void *arg) {
  int loops = *(int *) arg;
  for (int i = 0; i < loops; ++i) {
    pthread_mutex_lock(&mutex);
    int temp = global;
    temp++;
    global = temp;
    pthread_mutex_unlock(&mutex);
  }
  pthread_exit(NULL);
}

int main(int argc, char *argv[]) {
  pthread_t tid[2] = {0};
  int loops = 0;
  if (argc != 2) {
    fprintf(stderr, "Usage: <%s> <count loops>\n", argv[0]);
    exit(EXIT_FAILURE);
  }

  loops = atoi(argv[1]);
  for (int i = 0; i < 2; ++i) {
    int err = pthread_create(&tid[i], NULL, do_thread, &loops);
    if (err != 0) {
      fprintf(stderr, "[ERROR] pthread_create(): < %s > \n", strerror(err));
      exit(EXIT_FAILURE);
    }
  }

  pthread_join(tid[0], NULL);
  pthread_join(tid[1], NULL);

  printf("global = %d\n", global);
  return 0;
}*/
