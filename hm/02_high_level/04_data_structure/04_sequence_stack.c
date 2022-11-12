#include "head.h"
#include "./lib_sequence_stack/lib_sequence_stack.h"

void sequence_stack() {

  person_t p1 = {"aaa", 18};
  person_t p2 = {"bbb", 18};
  person_t p3 = {"ccc", 18};
  person_t p4 = {"ddd", 18};
  person_t p5 = {"eee", 18};

  seq_stack *stack = init_sequence_stack();

  push_sequence_stack(stack, &p1);
  push_sequence_stack(stack, &p2);
  push_sequence_stack(stack, &p3);
  push_sequence_stack(stack, &p4);
  push_sequence_stack(stack, &p5);

  while (is_empty_sequence_stack(stack) == 0) {
    person_t *p = top_sequence_stack(stack);
    printf("name: %s, age: %d\n", p->name, p->age);
    printf("stack size is: %d\n", size_sequence_stack(stack));
    pop_sequence_stack(stack);
    print_line();
  }
  printf("stack size is: %d\n", size_sequence_stack(stack));
  destroy_sequence_stack(stack);
}
