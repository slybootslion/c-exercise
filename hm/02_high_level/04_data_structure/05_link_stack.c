#include "head.h"
#include "./lib_link_stack/lib_link_stack.h"

typedef struct PersonLS {
  int *a;
  char name[64];
  int age;
} person_ls;

void link_stack_test() {
  person_ls p1 = {NULL, "aaa", 11};
  person_ls p2 = {NULL, "bbb", 22};
  person_ls p3 = {NULL, "ccc", 33};
  person_ls p4 = {NULL, "ddd", 44};
  person_ls p5 = {NULL, "eee", 55};

  link_stack *stack = init_link_stack();

  push_link_stack(stack, &p1);
  push_link_stack(stack, &p2);
  push_link_stack(stack, &p3);
  push_link_stack(stack, &p4);
  push_link_stack(stack, &p5);

  while (is_empty_link_stack(stack) == 0) {
    person_ls *p = top_link_stack(stack);
    printf("name: %s, age: %d\n", p->name, p->age);
    printf("stack size is: %d\n", size_link_stack(stack));
    pop_link_stack(stack);
    print_line();
  }
  printf("stack size is: %d\n", size_link_stack(stack));
  destroy_link_stack(stack);
}
