#include "head.h"

// 设计一个结构 struct perosn ,包含名字与年龄，在子线程中定义结构体变量，并传递给主线程进行打印

typedef struct Person {
  char name[64];
  int age;
} person_t;

void *struct_handler(void *arg) {
  static person_t p = {"zhangsan", 18};
  pthread_exit((void *) &p);
}

void fadenkommunikation() {
  pthread_t tid;
  int err = pthread_create(&tid, NULL, struct_handler, NULL);

  void *res = NULL;
  pthread_join(tid, &res);
  person_t person = *(person_t *) res;
  printf("person name is: %s, person age is: %d.\n", person.name, person.age);
}
