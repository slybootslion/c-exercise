#include "head.h"
#include "./lib_link_queue/lib_link_queue.h"

typedef struct PersonLS {
  int *a;
  char name[64];
  int age;
} person_ls;

void link_queue_exercise() {
  person_ls p1 = {NULL, "aaa", 11};
  person_ls p2 = {NULL, "bbb", 22};
  person_ls p3 = {NULL, "ccc", 33};
  person_ls p4 = {NULL, "ddd", 44};
  person_ls p5 = {NULL, "eee", 55};

  link_queue *queue = init_link_queue();

  push_link_queue(queue, &p1);
  push_link_queue(queue, &p2);
  push_link_queue(queue, &p3);
  push_link_queue(queue, &p4);
  push_link_queue(queue, &p5);

  printf("queue size is: %d\n", size_link_queue(queue));

  while (is_empty_link_queue(queue) == 0) {
    person_ls *front_person = front_link_queue(queue);
    printf("front person name: %s age: %d\n", front_person->name, front_person->age);

    person_ls *back_person = back_link_queue(queue);
    printf("back person name: %s age: %d\n", back_person->name, back_person->age);

    pop_link_queue(queue);
    print_line();
  }

  printf("queue size is: %d\n", size_link_queue(queue));

  destroy_link_queue(queue);
}
