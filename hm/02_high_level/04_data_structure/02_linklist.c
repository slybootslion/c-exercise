#include "head.h"

typedef struct link_node {
  void *data;
  struct link_node *next;
} node_t;

typedef struct linklist {
  node_t p_head; // 头节点
  int size;
} linklist_t;

typedef void *link_list;

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

int linklist_size(link_list list) {
  if (list == NULL)
    return -1;
  linklist_t *linklist = list;
  return linklist->size;
}

void clean_linklist(link_list list) {
  if (list == NULL)
    return;
  linklist_t *linklist = list;
  node_t *curr = linklist->p_head.next;
  for (int i = 0; i < linklist->size; ++i) {
    node_t *next = curr->next;
    free(curr);
    curr = next;
  }
  linklist->p_head.next = NULL;
  linklist->size = 0;
}

void destroy_linklist(link_list list) {
  if (list == NULL)
    return;
  clean_linklist(list);
  free(list);
  list = NULL;
}

/*  */
void linklist() {
  person_t p1 = {"zhangsan1", 18};
  person_t p2 = {"zhangsan2", 18};
  person_t p3 = {"zhangsan3", 18};
  person_t p4 = {"zhangsan4", 18};
  person_t p5 = {"zhangsan5", 18};
  person_t p6 = {"zhangsan6", 28};

  link_list *list = init_linklist();

  insert_linklist(list, 0, &p1);
  insert_linklist(list, 0, &p2);
  insert_linklist(list, 1, &p3);
  insert_linklist(list, -1, &p4);
  insert_linklist(list, 1, &p5);
  insert_linklist(list, -1, &p6);

  foreach_linklist(list, print_person); // 2 5 3 1 4 6
  printf("linklist size is: %d\n", linklist_size(list));
  print_line();

  remove_linknode_by_pos(list, 4);
  foreach_linklist(list, print_person);
  printf("linklist size is: %d\n", linklist_size(list));
  print_line();

  person_t del_p = {"zhangsan2", 18};
  remove_linknode_by_value(list, &del_p, check_same_person);
  foreach_linklist(list, print_person);
  printf("linklist size is: %d\n", linklist_size(list));
  print_line();

  clean_linklist(list);
  foreach_linklist(list, print_person);
  printf("linklist size is: %d\n", linklist_size(list));
  print_line();

  destroy_linklist(list);
  list = NULL;
}
