#include "seqstack.h"

int main() {
  seqstack_t *s = create_empty_seqstack();

  int i = 0;
  while (!is_full_seqstack(s))
    push_seqstack(s, i++);

  printf("top: %d\n", get_top_data(s));
  printf("pop: %d\n", pop_seqstack(s));

  while (!is_empty_seqstack(s)) {
    data_t ret = pop_seqstack(s);
    printf("%d ", ret);
  }
  putchar('\n');

  return 0;
}
