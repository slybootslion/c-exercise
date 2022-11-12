#include "../head.h"
#include "lib_linklist.h"

link_list init_linklist() {
  linklist_t *list = malloc(sizeof(linklist_t));
  if (list == NULL)
    return NULL;

  list->p_head.data = NULL;
  list->p_head.next = NULL;
  list->size = 0;

  return list;
}

void insert_linklist(link_list list, int pos, void *data) {
  if (list == NULL || data == NULL)
    return;

  linklist_t *linklist = list;
  if (pos < 0 || pos > linklist->size)
    pos = linklist->size;

  node_t *current = &linklist->p_head;
  for (int i = 0; i < pos; ++i)
    current = current->next;

  // 创建新的节点
  node_t *node = malloc(sizeof(node_t));
  node->next = NULL;
  node->data = data;

  node->next = current->next;
  current->next = node;

  linklist->size++;
}

void remove_linknode_by_pos(link_list list, int pos) {
  linklist_t *linklist = list;
  if (list == NULL || pos < 0 || pos > linklist->size - 1)
    return;

  node_t *current = &linklist->p_head;
  for (int i = 0; i < pos; ++i)
    current = current->next;

  node_t *del_node = current->next;
  current->next = del_node->next;
  free(del_node);
  del_node = NULL;

  linklist->size--;
}

void remove_linknode_by_value(link_list list, void *value, int (*callback)(void *, void *)) {
  if (list == NULL || value == NULL)
    return;
  linklist_t *linklist = list;

  node_t *curr = linklist->p_head.next;
  node_t *pre = &linklist->p_head;
  for (int i = 0; i < linklist->size; ++i) {
    if (callback(value, curr->data)) {
      pre->next = curr->next;
      free(curr);
      curr = NULL;
      linklist->size--;
      break;
    }
    pre = curr;
    curr = curr->next;
  }
}

void foreach_linklist(link_list list, void(*callback)(void *)) {
  if (list == NULL)
    return;

  linklist_t *linklist = list;
  node_t *node = linklist->p_head.next;
  for (int i = 0; i < linklist->size; ++i) {
    callback(node->data);
    node = node->next;
  }
}
