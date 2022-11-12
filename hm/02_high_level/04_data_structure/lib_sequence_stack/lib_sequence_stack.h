#ifndef INC_04_DATA_STRUCTURE_LIB_SEQUENCE_STACK_LIB_SEQUENCE_STACK_H_
#define INC_04_DATA_STRUCTURE_LIB_SEQUENCE_STACK_LIB_SEQUENCE_STACK_H_
#include "../head.h"

#define MAX 1024

typedef void *seq_stack;

seq_stack init_sequence_stack();

void push_sequence_stack(seq_stack s, void *data);

void pop_sequence_stack(seq_stack s);

void *top_sequence_stack(seq_stack s);

int size_sequence_stack(seq_stack s);

int is_empty_sequence_stack(seq_stack s);

void destroy_sequence_stack(seq_stack s);

#endif //INC_04_DATA_STRUCTURE_LIB_SEQUENCE_STACK_LIB_SEQUENCE_STACK_H_
