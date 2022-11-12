#include "../head.h"

#ifndef INC_04_DATA_STRUCTURE_LIB_LINKLIST_COMPANY_LIB_LINKLIST_C_H_
#define INC_04_DATA_STRUCTURE_LIB_LINKLIST_COMPANY_LIB_LINKLIST_C_H_

typedef struct link_node_c {
  struct link_node_c *next;
} node_c_t;

typedef struct linklist_c {
  node_c_t p_head; // 头节点
  int size;
} linklist_c_t;

typedef void * link_list_c;

extern link_list_c init_linklist_c();
extern void insert_linklist_c(link_list_c list, int pos, void *data);
extern void foreach_linklist_c(link_list_c list, void(*callback)(void *));
extern void remove_linknode_by_pos_c(link_list_c list, int pos);
extern void destroy_linklist(link_list_c list);

#endif //INC_04_DATA_STRUCTURE_LIB_LINKLIST_COMPANY_LIB_LINKLIST_C_H_
