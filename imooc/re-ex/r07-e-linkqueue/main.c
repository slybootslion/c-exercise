#include "linkstack.h"

int main() {
  linkqueue_t *q = create_empty_linkqueue();
  for (int i = 0; i < 10; ++i)
    enter_linkqueue(q, i);
  while (!is_empty_linkqueue(q))
    printf("%d ", delete_linkqueue(q));
  putchar('\n');
  return 0;
}
