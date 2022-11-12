#include "lib_linklist_c.h"

link_list_c init_linklist_c() {
  linklist_c_t *list = malloc(sizeof(linklist_c_t));
  if (list == NULL)
    return NULL;

  list->size = 0;
  list->p_head.next = NULL;

  return list;
}

void insert_linklist_c(link_list_c list, int pos, void *data) {
  if (list == NULL || data == NULL)
    return;

  linklist_c_t *linklist = list;
  if (pos < 0 || pos > linklist->size)
    pos = linklist->size;

  node_c_t *current = &linklist->p_head;
  for (int i = 0; i < pos; ++i)
    current = current->next;

  // 创建新的节点
  node_c_t *node = data;
  node->next = current->next;
  current->next = node;

  linklist->size++;
}

void remove_linknode_by_pos_c(link_list_c list, int pos) {
  linklist_c_t *linklist = list;
  if (list == NULL || pos < 0 || pos > linklist->size - 1)
    return;

  node_c_t *current = &linklist->p_head;
  for (int i = 0; i < pos; ++i)
    current = current->next;
  node_c_t *del_node = current->next;
  current->next = del_node->next;

  linklist->size--;
}

void destroy_linklist(link_list_c list) {
  if (list == NULL)
    return;
  free(list);
  list = NULL;
}

void foreach_linklist_c(link_list_c list, void(*callback)(void *)) {
  if (list == NULL)
    return;
  linklist_c_t *linklist = list;
  node_c_t *node = linklist->p_head.next;
  for (int i = 0; i < linklist->size; ++i) {
    callback(node);
    node = node->next;
  }

}
