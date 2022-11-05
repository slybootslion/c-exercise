#include "head.h"

// 静态链表
void test01() {
  link_node_t node1 = {10, NULL};
  link_node_t node2 = {20, NULL};
  link_node_t node3 = {30, NULL};
  link_node_t node4 = {40, NULL};
  link_node_t node5 = {50, NULL};

  node1.next = &node2;
  node2.next = &node3;
  node3.next = &node4;
  node4.next = &node5;

  link_node_t *p_current = &node1;
  while (p_current != NULL) {
    printf("%d ", p_current->num);
    p_current = p_current->next;
  }
  putchar('\n');
}

void test02() {
  link_node_t *node1 = malloc(sizeof(link_node_t));
  link_node_t *node2 = malloc(sizeof(link_node_t));
  link_node_t *node3 = malloc(sizeof(link_node_t));
  link_node_t *node4 = malloc(sizeof(link_node_t));
  link_node_t *node5 = malloc(sizeof(link_node_t));

  node1->num = 1;
  node1->next = node2;
  node2->num = 2;
  node2->next = node3;
  node3->num = 3;
  node3->next = node4;
  node4->num = 4;
  node4->next = node5;
  node5->num = 5;
  node5->next = NULL;

  link_node_t *p_current = node1;
  while (p_current != NULL) {
    printf("%d ", p_current->num);
    p_current = p_current->next;
  }
  putchar('\n');

  free(node1);
  free(node2);
  free(node3);
  free(node4);
  free(node5);
}
