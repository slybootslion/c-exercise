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
  if (p_head->next == NULL) {
    printf("链表为空.\n");
    return;
  }
  printf("遍历链表结果\n");
  link_node_t *temp = p_head->next;
  while (temp != NULL) {
    printf("%d ", temp->num);
    temp = temp->next;
  }
  putchar('\n');
}

void insert_linklist(link_node_t *p_head, int old_val, int new_val) {
  if (p_head == NULL)
    return;
  link_node_t *prev = p_head;
  link_node_t *curr = p_head->next;

  while (curr != NULL) {
    if (curr->num == old_val)
      break;
    prev = prev->next;
    curr = curr->next;
  }

  link_node_t *new_node = malloc(sizeof(link_node_t));
  new_node->num = new_val;
  new_node->next = curr;
  prev->next = new_node;
}

void remove_linklist(link_node_t *p_head, int val) {
  if (p_head == NULL)
    return;
  link_node_t *prev = p_head;
  link_node_t *curr = p_head->next;

  while (curr != NULL) {
    if (curr->num == val) {
      prev->next = curr->next;
      free(curr);
      curr = NULL;
      return;
    }
    curr = curr->next;
    prev = prev->next;
  }

}

void test03() {
  link_node_t *p = init_linklist();
  foreach_linklist(p);

  insert_linklist(p, 20, 100);
  insert_linklist(p, 21, 1000);

  foreach_linklist(p);

  remove_linklist(p, 100);
  remove_linklist(p, 200);
  foreach_linklist(p);
}
