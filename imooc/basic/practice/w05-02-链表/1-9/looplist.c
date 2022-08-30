//
// Created by SlybootsLion on 2022/8/30.
//
#include "head.h"

loopnode_t *create_empty_looplist() {
    loopnode_t *head = NULL;

    head = (loopnode_t *) malloc(sizeof(loopnode_t));
    if (NULL == head) {
        printf("malloc is fail!\n");
        return NULL;
    }

    memset(head, 0, sizeof(loopnode_t));

    head->next = head;

    return head;
}

int is_empty_looplist(loopnode_t *head) {
    return head->next == head ? 1 : 0;
}

void insert_head_looplist(loopnode_t *head, datatype_t data) {
    loopnode_t *temp = NULL;
    temp = (loopnode_t *) malloc(sizeof(loopnode_t));
    temp->data = data;
    temp->next = head->next;
    head->next = temp;
}

void printf_data_looplist(loopnode_t *head) {
    loopnode_t *p = head;
    while (p->next != head) {
        printf("%d ", p->next->data);
        p = p->next;
    }
    putchar('\n');
}
