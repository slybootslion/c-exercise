#include <malloc.h>
#include <string.h>

//
// Created by SlybootsLion on 2022/8/30.
//
typedef int data_t;

#define N 5

typedef struct {
    data_t buf[N];
    int front;
    int rear;
} loopqueue_t;

loopqueue_t *create_empty_loopqueue() {
    loopqueue_t *q = NULL;
    q = (loopqueue_t *) malloc(sizeof(loopqueue_t));
    memset(q, 0, sizeof(loopqueue_t));
    q->front = q->rear = 0;
    return q;
}

int is_empty_loopqueue(loopqueue_t *q) {
    return q->front == q->rear;
}

int is_full_loopqueue(loopqueue_t *q) {
    return q->front == (q->rear + 1) % N;
}

void enter_loopqueue(loopqueue_t *q, data_t data) {
    q->buf[q->rear] = data;
    q->rear = (q->rear + 1) % N;
}

data_t delete_loopqueue(loopqueue_t *q) {
    data_t data;

    data = q->buf[q->front];
    q->front = (q->front + 1) % N;

    return data;
}

int main () {
    int i = 0;
    loopqueue_t *q = NULL;

    q = create_empty_loopqueue();

    while (!is_full_loopqueue(q))
        enter_loopqueue(q, i++);

    while (!is_empty_loopqueue(q))
        printf("%d ", delete_loopqueue(q));
    printf("\n");

    return 0;
}
