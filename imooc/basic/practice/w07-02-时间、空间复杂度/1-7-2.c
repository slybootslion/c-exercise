//
// Created by SlybootsLion on 2022/9/14.
//

#include <stddef.h>

typedef struct LinkNode {
    int val;
    struct LinkNode *next;
} linknode_t;

void sort_linklist(linknode_t *head) {
    linknode_t *p = head->next;
    linknode_t *q = head->next->next;
    while (p != NULL) {
        while (q != NULL) {
            if (q->next != NULL) {
                if (q->val > q->next->val) {
                    int temp = q->val;
                    q->val = q->next->val;
                    q->next->val = temp;
                }
            }
            q = q->next;
        }
        p = p->next;
    }
}
