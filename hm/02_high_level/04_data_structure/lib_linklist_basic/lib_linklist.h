#ifndef INC_04_DATA_STRUCTURE_LIB_LINKLIST_BASIC_LIB_LINKLIST_H_
#define INC_04_DATA_STRUCTURE_LIB_LINKLIST_BASIC_LIB_LINKLIST_H_

typedef struct link_node {
  void *data;
  struct link_node *next;
} node_t;

typedef struct linklist {
  node_t p_head; // 头节点
  int size;
} linklist_t;

typedef void *link_list;

link_list init_linklist();

void insert_linklist(link_list list, int pos, void *data);

void remove_linknode_by_pos(link_list list, int pos);

void remove_linknode_by_value(link_list list, void *value, int (*callback)(void *, void *));

void foreach_linklist(link_list list, void(*callback)(void *));

#endif //INC_04_DATA_STRUCTURE_LIB_LINKLIST_BASIC_LIB_LINKLIST_H_
