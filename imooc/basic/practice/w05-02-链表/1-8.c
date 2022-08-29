//
// Created by SlybootsLion on 2022/8/29.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    int data;
    struct node *next;
} linknode_t;

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

void insert_head_linklist(linknode_t *head, int data) {
    linknode_t *temp = (linknode_t *) malloc(sizeof(linknode_t));
    temp->data = data;
    temp->next = head->next;
    head->next = temp;
}

void printf_data_linklist(linknode_t *head) {
    linknode_t *p = head;
    while (p->next != NULL) {
        printf("%d\t", p->next->data);
        p = p->next;
    }
    putchar('\n');
}

void revers_data_linklist(linknode_t *head) {
    linknode_t *p = NULL;
    linknode_t *temp = NULL;
    p = head->next->next;
    head->next->next = NULL;
    while (p != NULL) {
        temp = p->next;
        p->next = head->next;
        head->next = p;
        p = temp;
    }
}

void clean_up_linklist(linknode_t *head) {
    linknode_t *p = head;
    linknode_t *temp = NULL;
    while (p != NULL) {
        temp = p->next;
        printf_data_linklist(p);
        free(p);
        p = temp;
    }
}

int main() {
    int arr[] = {1, 5, 3, 7, 9};
    linknode_t *l = create_empty_linklist();
    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); ++i)
        insert_head_linklist(l, arr[i]);
    printf("原链表：\n");
    printf_data_linklist(l);

    revers_data_linklist(l);
    printf("倒置后：\n");
    printf_data_linklist(l);

    printf("删除中：\n");
    clean_up_linklist(l);

    printf("删除后：\n");
    printf_data_linklist(l);
    return 0;
}
