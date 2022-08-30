#include <malloc.h>
#include <string.h>

//
// Created by SlybootsLion on 2022/8/30.
//
typedef int data_t;

#define MAX 5

typedef struct {
    data_t buf[MAX];
    int top;
} seqstack_t;

seqstack_t *create_empty_seqstack() {
    seqstack_t *s = (seqstack_t *) malloc(sizeof(seqstack_t));
    if (s == NULL) {
        printf("malloc is fail\n");
        return NULL;
    }
    memset(s, 0, sizeof(seqstack_t));
    s->top = -1;
    return s;
}

int is_empty_seqstack(seqstack_t *s) {
    return s->top == -1 ? 1 : 0;
}

int is_full_seqstack(seqstack_t *s) {
    return s->top == MAX - 1 ? 1 : 0;
}

void push_seqstack(seqstack_t *s, data_t data) {
    s->buf[++s->top] = data;
}

data_t pop_seqstack(seqstack_t *s) {
    return s->buf[s->top--];
}

data_t get_top_data(seqstack_t *s) {
    return s->buf[s->top];
}

int main () {
    int i = 0;
    data_t ret = 0;
    seqstack_t *s = create_empty_seqstack();
    while (!is_full_seqstack(s))
        push_seqstack(s, i++);

    printf("top: %d\n", get_top_data(s));

    printf("pop :%d\n", pop_seqstack(s));

    while (!is_empty_seqstack(s)){
        ret = pop_seqstack(s);
        printf("%d ", ret);
    }
    putchar('\n');

    return 0;
}
