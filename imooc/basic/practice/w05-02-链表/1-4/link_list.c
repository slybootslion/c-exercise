//
// Created by SlybootsLion on 2022/8/29.
//
#include "head.h"

linknode_t *create_empty_linklist() {
    linknode_t *head = (linknode_t *) malloc(sizeof(linknode_t));
    if (head == NULL) {
        printf("malloc error!\n");
        return NULL;
    }
    memset(head, 0, sizeof(linknode_t));
    head->next = NULL;
    return head;
}

void insert_order_linklist(linknode_t *head, int data) {
    linknode_t *temp = NULL;
    temp = (linknode_t *) malloc(sizeof(linknode_t));
    temp->data = data;
    linknode_t *p = head;
    while (p->next != NULL && data < p->next->data)
        p = p->next;
    temp->next = p->next;
    p->next = temp;
}

void printf_data_linklist(linknode_t *head) {
    linknode_t *p = head;
    while (p->next != NULL) {
        printf("%d\t", p->next->data);
        p = p->next;
    }
    putchar('\n');
}
