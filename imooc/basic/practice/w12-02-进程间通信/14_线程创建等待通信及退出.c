#include "head.h"

void *do_thread_one(void *arg) {
  printf("THREAD one START.\n");
  pthread_exit(NULL);
}
void *do_thread_two(void *arg) {
  printf("THREAD two START.\n");
  pthread_exit(NULL);
}

void *do_thread_same(void *arg) {
  for (int i = 0; i < 5; ++i) {
    printf("i = %d\n", i);
    sleep(1);
  }
  pthread_exit(NULL);
}

void test09() {
  int err;
  pthread_t tid_one = 0, tid_two = 0, tid[2] = {0};

  err = pthread_create(&tid_one, NULL, do_thread_one, NULL);
  if (err != 0) {
    fprintf(stderr, "[ERROR] pthread_create: <%s>\n", strerror(err));
    exit(EXIT_FAILURE);
  }

  err = pthread_create(&tid_two, NULL, do_thread_two, NULL);
  if (err != 0) {
    fprintf(stderr, "[ERROR] pthread_create: <%s>\n", strerror(err));
    exit(EXIT_FAILURE);
  }

  printf("tid1 = %ld\n", tid_one);
  pthread_join(tid_one, NULL);
  printf("tid2 = %ld\n", tid_two);
  pthread_join(tid_two, NULL);

  for (int i = 0; i < 2; ++i) {
    err = pthread_create(&tid[i], NULL, do_thread_same, NULL);
    if (err != 0) {
      fprintf(stderr, "[ERROR] pthread_create: <%s>\n", strerror(err));
      exit(EXIT_FAILURE);
    }
  }

  pthread_join(tid[0], NULL);
  pthread_join(tid[1], NULL);
}

void *do_thread(void *arg) {
  static int retval = 100;
  int num = *(int *) arg;
  printf("thread start.\n");
  printf("num = %d\n", num);
  pthread_exit((void *) &retval);
}

void test10() {
  pthread_t tid;
  int num = 100;
  int err = pthread_create(&tid, NULL, do_thread, &num);
  if (err != 0) {
    fprintf(stderr, "[ERROR] pthread_create: <%s>\n", strerror(err));
    exit(EXIT_FAILURE);
  }

  void *pret = NULL;
  pthread_join(tid, &pret);
  printf("ret = %d\n", *(int *) pret);
}
