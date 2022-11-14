#include "head.h"

typedef struct binary_node {
  char ch;
  struct binary_node *l_child;
  struct binary_node *r_child;
} binary_node_t;

void recursion(binary_node_t *root) {
  if (root == NULL)
    return;
  printf("%c -> ", root->ch);
  recursion(root->l_child);
  recursion(root->r_child);
}

void recursion_tree_exercise() {
  binary_node_t node_a = {'A', NULL, NULL};
  binary_node_t node_b = {'B', NULL, NULL};
  binary_node_t node_c = {'C', NULL, NULL};
  binary_node_t node_d = {'D', NULL, NULL};
  binary_node_t node_e = {'E', NULL, NULL};
  binary_node_t node_f = {'F', NULL, NULL};
  binary_node_t node_g = {'G', NULL, NULL};
  binary_node_t node_h = {'H', NULL, NULL};

  node_a.l_child = &node_b;
  node_a.r_child = &node_f;
  node_b.r_child = &node_c;
  node_c.l_child = &node_d;
  node_c.r_child = &node_e;
  node_f.r_child = &node_g;
  node_g.l_child = &node_h;

  recursion(&node_a);
  putchar('\n');
  print_line();
}
