#include "loopqueue.h"

int main() {
  loopqueue_t *q = create_empty_loopqueue();
  int i = 0;
  while (!is_full_loopqueue(q))
    enter_loopqueue(q, ++i);
  while (!is_empty_loopqueue(q))
    printf("%d ", delete_loopqueue(q));
  putchar('\n');
  return 0;
}
