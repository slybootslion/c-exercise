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

int is_empty_linklist(linknode_t *head) {
    return head->next == NULL ? 1 : 0;
}

int delete_data_linklist(linknode_t *head, int data) {
    linknode_t *p = head;
    int flag = 0;
    if (is_empty_linklist(head))
        return -2;
    while (p->next != NULL) {
        if (p->next->data == data) {
            p->next = p->next->next;
            flag = 1;
        } else {
            p = p->next;
        }
    }
    if (flag == 0)
        return -2;
    else
        printf("delete %d is successful!\n", data);
    return 0;
}
