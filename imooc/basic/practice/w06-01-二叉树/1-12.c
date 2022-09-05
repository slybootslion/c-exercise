//
// Created by SlybootsLion on 2022/9/5.
//

#include <malloc.h>
#include <string.h>
#include <stdlib.h>

typedef struct bitree {
    int n;
    char data;
    struct bitree *lchild;
    struct bitree *rchild;
} bitree_t;

typedef bitree_t data_t;

#define N 6

typedef struct {
    data_t buf[N];
    int front;
    int rear;
} loopqueue_t;

loopqueue_t *create_empty_loopqueue() {
    loopqueue_t *q = NULL;

    q = (loopqueue_t *) malloc(sizeof(loopqueue_t));
    memset(q, 0, sizeof(loopqueue_t));
    q->front = q->rear = 0;

    return q;
}

int is_empty_loopqueue(loopqueue_t *q) {
    return q->front == q->rear;
}

void enter_loopqueue(loopqueue_t *q, data_t data) {
    q->buf[q->rear] = data;
    q->rear = (q->rear + 1) % N;
}

data_t delete_loopqueue(loopqueue_t *q) {
    data_t data = q->buf[q->front];
    q->front = (q->front + 1) % N;
    return data;
}

int i = 0;
char arr[] = {'A', 'B', 'D', 'E', 'C', 'F'};

bitree_t *create_binatry_tree(int n) {
    bitree_t *root = NULL;
    root = (bitree_t *) malloc(sizeof(bitree_t));
    memset(root, 0, sizeof(bitree_t));

    root->n = n;
    root->lchild = root->rchild = NULL;
    root->data = arr[i++];
    if (2 * n <= N)
        root->lchild = create_binatry_tree(2 * n);
    if (2 * n + 1 <= N)
        root->rchild = create_binatry_tree(2 * n + 1);

    return root;
}

void level_order(bitree_t *root) {
    loopqueue_t *s = create_empty_loopqueue();
    enter_loopqueue(s, *root);
    int level = 1;
    while (!is_empty_loopqueue(s)) {
        int l = s->rear;
        int r = s->front;
        for (int i = 0; i < abs(l - r); ++i) {
            bitree_t node = delete_loopqueue(s);
            printf("level %d: %c\n", level, node.data);
            if (node.lchild)
                enter_loopqueue(s, *node.lchild);
            if (node.rchild)
                enter_loopqueue(s, *node.rchild);
        }
        level++;
    }
}

int main() {
    bitree_t *tree = create_binatry_tree(1);
    printf("created tree success\n");
    level_order(tree);
    return 0;
}
