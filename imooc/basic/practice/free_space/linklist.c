//
// Created by ubuntu on 22-8-31.
//
#include "linklist.h"

// 创建空的链表---为头结点在堆区分配空间
linklist_t *create_empty_linklist() {
    linklist_t *head = NULL;

    // 1.1 分配堆区空间
    head = (linklist_t *) malloc(sizeof(linklist_t));
    if (NULL == head) {
        printf("malloc failed!\n");
        return NULL;
    }

    memset(head, 0, sizeof(linklist_t));
    // head->next = NULL;
    // head->data = 0;
    return head;
}

// 尾插法
// 特点：插入的顺序和输出的顺序是相同的
void insert_tail_linklist(linklist_t *head, datatype_t data) {
    // 3.1 为结点在堆区申请空间
    linklist_t *temp = (linklist_t *) malloc(sizeof(linklist_t));
    if (NULL == temp) {
        printf("malloc failed!\n");
    }

    // 3.2 插入数据
    temp->data = data;

    // 3.3 找到尾结点
    linklist_t *tail = head;
    while (tail->next != NULL) {
        tail = tail->next;
    }

    // 3.4 连接结点
    temp->next = tail->next;
    tail->next = temp;
}

// 输出链表中的内容
void print_data_linklist(linklist_t *head) {
    linklist_t *p = head;

    while (p->next != NULL) {
        printf("%d ", p->next->data);
        p = p->next;
    }
    printf("\n");
}

// 在单向链表中实现冒泡排序
//void sort_linklist(linklist_t *head) {
//    linklist_t *p = NULL;
//    linklist_t *q = NULL;
//    linklist_t *tail = NULL;
//
//    while (head->next != tail) {
//        p = head;
//        while (p->next != tail && p->next->next != tail) {
//            if (p->next->data > p->next->next->data) {
//                q = p->next;
//                p->next = p->next->next;
//                q->next = p->next->next;
//                p->next->next = q;
//                q = NULL;
//            }
//            p = p->next;
//        }
//        tail = p->next;
//    }
//}

void sort_linklist(linklist_t *head) {
    linklist_t *p = head->next;
    linklist_t *q = NULL;
    while (p != NULL) {
        q = p->next;
        while (q != NULL) {
            if (p->data > q->data) {
                linklist_t *temp = p;
                p = q->next;
                q->next = p;
                p->next = temp;
            }
            q = q->next;
        }
        p = p->next;
    }
}
