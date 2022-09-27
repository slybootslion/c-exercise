#include "linkstack.h"

int main() {
  linkstack_t *s = create_empty_linkstack();
  data_t arr[] = {'a', 'n', 'i', 'h', 'c'};
  for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); ++i)
    push_linkstack(s, arr[i]);

  printf("top data: %c\n", get_top_data(s));

  while (!is_empty_linkstack(s))
    printf("%c", pop_linkstack(s));
  putchar('\n');

  return 0;
}
