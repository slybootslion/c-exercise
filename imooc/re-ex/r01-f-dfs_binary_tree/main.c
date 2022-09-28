#include "bitree.h"

int main() {
  bitree_t *root = create_binary_tree(1);
  printf("create is successful!\n");

  printf("pre_order:");
  pre_order(root);
  putchar('\n');

  printf("in_order:");
  in_order(root);
  putchar('\n');

  printf("post_order:");
  post_order(root);
  putchar('\n');

  return 0;
}
