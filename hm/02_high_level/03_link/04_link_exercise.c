#include "head.h"

// 链表的反转
void revers_linklist(link_node_t *p_head) {
  if (p_head == NULL)
    return;

  link_node_t *prev = NULL;
  link_node_t *next = NULL;
  link_node_t *current = p_head->next;

  while (current != NULL) {
    next = current->next;
    current->next = prev;
    prev = current;
    current = next;
  }
  p_head->next = prev;
}

// 统计链表个数
int linklist_size(link_node_t *p_head) {
  if (p_head == NULL)
    return -1;

  link_node_t *p = p_head->next;
  int count = 0;
  while (p != NULL) {
    count++;
    p = p->next;
  }
  return count;
}

void linklist_exercise() {
  printf("revers linklist:\n");

  link_node_t *p = init_linklist();
  insert_linklist(p, 0, 10);
  insert_linklist(p, 0, 20);
  insert_linklist(p, 0, 30);
  insert_linklist(p, 0, 40);
  foreach_linklist(p);

  revers_linklist(p);
  foreach_linklist(p);

  int count = linklist_size(p);
  printf("linklist size is: %d\n", count);
}
