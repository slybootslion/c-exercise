#include "head.h"
#include "./lib_sequence_stack/lib_sequence_stack.h"

typedef struct binary_node {
  char ch;
  struct binary_node *l_child;
  struct binary_node *r_child;
  int flag;
} binary_node_t;

void recursion(binary_node_t *root) {
  if (root == NULL)
    return;
  printf("%c -> ", root->ch);
  recursion(root->l_child);
  recursion(root->r_child);
}

void iteration(binary_node_t *root) {
  seq_stack *stack = init_sequence_stack();
  push_sequence_stack(stack, root);
  while (size_sequence_stack(stack) > 0) {
    binary_node_t *node = top_sequence_stack(stack);
    pop_sequence_stack(stack);
    if (node->flag == 1) {
      printf("%c -> ", node->ch);
      continue;
    }
    node->flag = 1;
    if (node->r_child != NULL)
      push_sequence_stack(stack, node->r_child);
    if (node->l_child != NULL)
      push_sequence_stack(stack, node->l_child);
    push_sequence_stack(stack, node);
  }
  destroy_sequence_stack(stack);
  stack = NULL;
}

void btree_test01(binary_node_t *root) {
  recursion(root);
  putchar('\n');
}

void leaves_count(binary_node_t *root, int *count) {
  if (root == NULL)
    return;
  if (root->r_child == NULL && root->l_child == NULL)
    (*count)++;
  leaves_count(root->l_child, count);
  leaves_count(root->r_child, count);
}

void btree_test02(binary_node_t *root) {
  int count = 0;
  leaves_count(root, &count);
  printf("leaves count is: %d\n", count);
}

int get_tree_height(binary_node_t *root) {
  if (root == NULL)
    return 0;
  int lh = get_tree_height(root->l_child);
  int rh = get_tree_height(root->r_child);
  return lh > rh ? lh + 1 : rh + 1;
}

void btree_test03(binary_node_t *root) {
  int height = get_tree_height(root);
  printf("tree height is: %d\n", height);
}

binary_node_t *copy_tree(binary_node_t *root) {
  if (root == NULL)
    return NULL;
  binary_node_t *l_tree = copy_tree(root->l_child);
  binary_node_t *r_tree = copy_tree(root->r_child);
  binary_node_t *node = malloc(sizeof(binary_node_t));
  node->l_child = l_tree;
  node->r_child = r_tree;
  node->ch = root->ch;
  return node;
}

void destroy_tree(binary_node_t *root) {
  if (root == NULL)
    return;
  destroy_tree(root->l_child);
  destroy_tree(root->r_child);
  printf("%c freed\n", root->ch);
  free(root);
  root = NULL;
}

void btree_test04(binary_node_t *root) {
  recursion(root);
  putchar('\n');
  print_line();
  binary_node_t *c_tree = copy_tree(root);
  recursion(c_tree);
  putchar('\n');

  destroy_tree(c_tree);
  c_tree = NULL;
}

void btree_test05(binary_node_t *root) {
  iteration(root);
  putchar('\n');
}

void tree_exercise() {
  binary_node_t node_a = {'A', NULL, NULL, 0};
  binary_node_t node_b = {'B', NULL, NULL, 0};
  binary_node_t node_c = {'C', NULL, NULL, 0};
  binary_node_t node_d = {'D', NULL, NULL, 0};
  binary_node_t node_e = {'E', NULL, NULL, 0};
  binary_node_t node_f = {'F', NULL, NULL, 0};
  binary_node_t node_g = {'G', NULL, NULL, 0};
  binary_node_t node_h = {'H', NULL, NULL, 0};

  node_a.l_child = &node_b;
  node_a.r_child = &node_f;
  node_b.r_child = &node_c;
  node_c.l_child = &node_d;
  node_c.r_child = &node_e;
  node_f.r_child = &node_g;
  node_g.l_child = &node_h;

//  btree_test01(&node_a);
//  btree_test02(&node_a);
//  btree_test03(&node_a);
//  btree_test04(&node_a);
  btree_test05(&node_a);
}
