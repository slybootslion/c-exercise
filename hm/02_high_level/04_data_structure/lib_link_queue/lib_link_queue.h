#ifndef INC_04_DATA_STRUCTURE_LIB_LINK_QUEUE_LIB_LINK_QUEUE_H_
#define INC_04_DATA_STRUCTURE_LIB_LINK_QUEUE_LIB_LINK_QUEUE_H_

#include "../head.h"

typedef struct link_node {
  struct link_node *next;
} link_node_t;

typedef void * link_queue;

link_queue init_link_queue();
void push_link_queue(link_queue queue, void *data);
void pop_link_queue(link_queue queue);
void *front_link_queue(link_queue queue);
void *back_link_queue(link_queue queue);
int size_link_queue(link_queue queue);
int is_empty_link_queue(link_queue queue);
void destroy_link_queue(link_queue queue);

#endif //INC_04_DATA_STRUCTURE_LIB_LINK_QUEUE_LIB_LINK_QUEUE_H_
