#include "head.h"

static int global = 0;

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void *do_thread(void *arg) {
  int loops = *(int *) arg;
  int i, tmp = 0;
  for (i = 0; i < loops; i++) {
    pthread_mutex_lock(&mutex);
    tmp = global;
    tmp++;
    global = tmp;
    pthread_mutex_unlock(&mutex);
  }
  pthread_exit(NULL);
}

void test11(int argc, char *argv[]) {
  int err, i = 0;
  pthread_t tid[2] = {0};
  int loops = 0;
  if (argc != 2) {
    fprintf(stderr, "usage: <%s> <count loops>\n", argv[0]);
    exit(EXIT_FAILURE);
  }

  loops = atoi(argv[1]);
  for (i = 0; i < 2; ++i) {
    err = pthread_create(&tid[i], NULL, do_thread, &loops);
    if (err != 0) {
      fprintf(stderr, "[ERROR] pthread_create(): <%s> \n", strerror(err));
      exit(EXIT_FAILURE);
    }
  }

  pthread_join(tid[0], NULL);
  pthread_join(tid[1], NULL);
  printf("global = %d\n", global);
}
