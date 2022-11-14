#include "head.h"
#include "./lib_sequence_queue/lib_sequence_queue.h"

void sequence_queue() {
  seq_queue *queue = init_sequence_queue();
  person_t p1 = {"aaa", 11};
  person_t p2 = {"bbb", 12};
  person_t p3 = {"ccc", 13};
  person_t p4 = {"ddd", 14};
  person_t p5 = {"eee", 15};

  push_sequence_queue(queue, &p1);
  push_sequence_queue(queue, &p2);
  push_sequence_queue(queue, &p3);
  push_sequence_queue(queue, &p4);
  push_sequence_queue(queue, &p5);

  printf("queue size is: %d\n", size_sequence_queue(queue));

  while (is_empty_sequence_queue(queue) == 0) {
    person_t *front_person = front_sequence_queue(queue);
    printf("front person name: %s age: %d\n", front_person->name, front_person->age);

    person_t *back_person = back_sequence_queue(queue);
    printf("back person name: %s age: %d\n", back_person->name, back_person->age);

    pop_sequence_queue(queue);
    print_line();
  }

  printf("queue size is: %d\n", size_sequence_queue(queue));

  destroy_sequence_queue(queue);
}
