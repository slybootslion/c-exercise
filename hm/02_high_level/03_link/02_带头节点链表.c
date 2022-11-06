#include "head.h"

link_node_t *init_linklist() {
  link_node_t *p_head = malloc(sizeof(link_node_t));
  if (p_head == NULL)
    return NULL;

  p_head->num = -1;
  p_head->next = NULL;

  link_node_t *p_tail = p_head;

  int val = -1;
  while (1) {
    printf("请插入数据，输入-1代表插入结束\n");
    scanf("%d", &val);
    if (val == -1)
      break;

    link_node_t *new_node = malloc(sizeof(link_node_t));
    new_node->num = val;
    new_node->next = NULL;

    p_tail->next = new_node;
    p_tail = new_node;
  }

  return p_head;
}

void foreach_linklist(link_node_t *p_head) {
  link_node_t *temp = p_head->next;
  while (temp != NULL) {
    printf("%d ", temp->num);
    temp = temp->next;
  }
}

void test03() {
  link_node_t *p = init_linklist();

  printf("遍历链表结果");
  foreach_linklist(p);
}
