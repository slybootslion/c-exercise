#ifndef INC_04_DATA_STRUCTURE_LIB_SEQUENCE_QUEUE_LIB_SEQUENCE_QUEUE_H_
#define INC_04_DATA_STRUCTURE_LIB_SEQUENCE_QUEUE_LIB_SEQUENCE_QUEUE_H_

#define MAX 1024

typedef void *seq_queue;

seq_queue init_sequence_queue();
void push_sequence_queue(seq_queue queue, void *data);
void pop_sequence_queue(seq_queue queue);
void *front_sequence_queue(seq_queue queue);
void *back_sequence_queue(seq_queue queue);
int size_sequence_queue(seq_queue queue);
int is_empty_sequence_queue(seq_queue queue);
void destroy_sequence_queue(seq_queue queue);

#endif //INC_04_DATA_STRUCTURE_LIB_SEQUENCE_QUEUE_LIB_SEQUENCE_QUEUE_H_
