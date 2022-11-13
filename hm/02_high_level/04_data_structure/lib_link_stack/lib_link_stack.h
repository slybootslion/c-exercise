#ifndef INC_04_DATA_STRUCTURE_LIB_LINK_STACK_LIB_LINK_STACK_H_
#define INC_04_DATA_STRUCTURE_LIB_LINK_STACK_LIB_LINK_STACK_H_
#include "../head.h"

typedef void *link_stack;

link_stack init_link_stack();

void push_link_stack(link_stack s, void *data);

void pop_link_stack(link_stack s);

void *top_link_stack(link_stack s);

int size_link_stack(link_stack s);

int is_empty_link_stack(link_stack s);

void destroy_link_stack(link_stack s);

#endif //INC_04_DATA_STRUCTURE_LIB_LINK_STACK_LIB_LINK_STACK_H_
