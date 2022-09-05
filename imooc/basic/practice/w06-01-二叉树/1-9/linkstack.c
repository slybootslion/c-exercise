//
// Created by SlybootsLion on 2022/9/5.
//
#include "linkstack.h"

linkstack_t *create_empty_linkstack() {
    linkstack_t *s = NULL;

    s = (linkstack_t *) malloc(sizeof(linkstack_t));
    if (s == NULL) {
        printf("malloc is fail\n");
        return NULL;
    }
    memset(s, 0, sizeof(linkstack_t));
    return s;
}

int is_empty_linkstack(linkstack_t *s) {
    return s->top == NULL;
}

void push_linkstack(linkstack_t *s, datatype_t data) {
    linknode_t *temp = NULL;

    temp = (linknode_t *) malloc(sizeof(linknode_t));
    if (NULL == temp) {
        printf("malloc is fail\n");
        return;
    }
    temp->data = data;
    s->top = temp;
    s->n++;
}

datatype_t pop_linkstack(linkstack_t *s) {
    linknode_t *temp = NULL;
    datatype_t data;

    temp = s->top;
    data = temp->data;
    s->top = temp->next;

    free(temp);
    temp = NULL;

    s->n--;

    return data;
}

datatype_t get_top_data(linkstack_t *s) {
    return s->top->data;
}
