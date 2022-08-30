//
// Created by SlybootsLion on 2022/8/30.
//
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define n 8

typedef struct node {
    int data;
    struct node *next;
} loop_list;


loop_list *create_empty_loop() {
    loop_list *head = (loop_list *) malloc(sizeof(loop_list));
    if (head == NULL) {
        printf("malloc error\n");
        return NULL;
    }
    memset(head, 0, sizeof(loop_list));
    head->next = head;
    return head;
}

void insert_tail_loop_list(loop_list *head, int data) {
    loop_list *t = (loop_list *) malloc(sizeof(loop_list));
    t->data = data;
    loop_list *p = head;
    while (p->next != head)
        p = p->next;
    t->next = p->next;
    p->next = t;
}

void printf_data_loop_list(loop_list *head) {
    loop_list *p = head;
    while (p->next != head) {
        printf("%d ", p->next->data);
        p = p->next;
    }
    putchar('\n');
}

void data_out_list(loop_list *p, int m) {
    loop_list *t = NULL;
    while (p != NULL) {
        for (int i = 1; i < m - 1; ++i)
            p = p->next;
        t = p->next;
        p->next = p->next->next;
        printf("%d is out\n", t->data);

        p = t != t->next ? p->next : NULL;
        free(t);
        t = NULL;
    }
}

loop_list *find_last_loop_list(loop_list *head) {
    loop_list *p = head;
    while (p->next != head)
        p = p->next;
    return p;
}

void handle_joseph(loop_list *head, int k, int m) {
    loop_list *p = head;

    while (p->next != head)
        p = p->next;
    p->next = head->next;
    p = p->next;

    while (--k)
        p = p->next;

    data_out_list(p, m);

}

// 设n=8，k=3，m=4时，出列序列为：(6，2，7，4，3，5，1，8)
int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8};
    loop_list *list = create_empty_loop();

    for (int i = 0; i < n; ++i)
        insert_tail_loop_list(list, arr[i]);

    printf("原数列：\n");
    printf_data_loop_list(list);
    printf("-----------------\n");

    handle_joseph(list, 3, 4);

    return 0;
}
