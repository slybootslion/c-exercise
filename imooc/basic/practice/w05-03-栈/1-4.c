#include <malloc.h>

//
// Created by SlybootsLion on 2022/8/30.
//
typedef char data_t;

typedef struct node {
    data_t data;
    struct node *next;
} linknode_t;

typedef struct {
    linknode_t *top;
    int n;
} linkstack_t;

linkstack_t *create_empty_linkstack() {
    linkstack_t *s = NULL;
    s = (linkstack_t *) malloc(sizeof(linkstack_t));
    s->top = NULL;
    s->n = 0;
    return s;
}

int is_empty_linkstack(linkstack_t *s) {
    return s->top == NULL;
}

int push_linkstack(linkstack_t *s, data_t data) {
    linknode_t *temp = NULL;
    temp = (linknode_t *) malloc(sizeof(linknode_t));
    temp->data = data;
    temp->next = s->top;
    s->top = temp;
    s->n++;
    return 0;
}

data_t pop_linkstack(linkstack_t *s) {
    linknode_t *temp = NULL;
    data_t data;
    temp = s->top;
    data = temp->data;
    s->top = temp->next;
    free(temp);
    temp = NULL;
    s->n--;
    return data;
}

data_t get_top_data(linkstack_t *s) {
    return s->top->data;
}

int main() {
    linkstack_t *s = NULL;
    data_t array[] = {'a', 'n', 'i', 'h', 'c'};

    s = create_empty_linkstack();

    for (int i = 0; i < sizeof(array) / sizeof(array[0]); ++i) {
        push_linkstack(s, array[i]);
    }

    printf("Top data: %c\n", get_top_data(s));

    while (!is_empty_linkstack(s))
        printf("%c", pop_linkstack(s));
    putchar('\n');

    return 0;
}
