//
// Created by SlybootsLion on 2022/9/3.
//
#include "bitree.h"
#include "linkstack.h"

bitree_t *create_binatry_tree(int n) {
    bitree_t *root = NULL;

    root = (bitree_t *) malloc(sizeof(bitree_t));
    memset(root, 0, sizeof(bitree_t));

    root->n = n;
    root->lchild = root->rchild = NULL;

    printf("Input %d node data : ", n);
    scanf("%c", &(root->data));

    while (getchar() != '\n');

    if (2 * n <= N)
        root->lchild = create_binatry_tree(2 * n);

    if (2 * n + 1 <= N)
        root->rchild = create_binatry_tree(2 * n + 1);

    return root;
}

void pre_order(bitree_t *root) {
    if (root == NULL)
        return;
    linkstack_t *s = create_empty_linkstack();
    bitree_t *temp = root;

    while (temp != NULL || !is_empty_linkstack(s)) {
        while (temp != NULL) {
            printf("(%d: %c) ", temp->n, temp->data);
            push_linkstack(s, temp);
            temp = temp->lchild;
        }

        if (!is_empty_linkstack(s)) {
            temp = pop_linkstack(s);
            temp = temp->rchild;
        }
    }

    free(s);
}

void in_order(bitree_t *root) {
    if (root == NULL)
        return;

    linkstack_t *s = create_empty_linkstack();
    bitree_t *temp = root;

    while (temp != NULL || !is_empty_linkstack(s)) {
        if (temp != NULL) {
            push_linkstack(s, temp);
            temp = temp->lchild;
        } else {
            temp = pop_linkstack(s);
            printf("(%d: %c) ", temp->n, temp->data);
            temp = temp->rchild;
        }
    }
    free(s);
}

void post_order(bitree_t *root) {
    if (root == NULL)
        return;

    linkstack_t *s = create_empty_linkstack();
    bitree_t *cur = NULL;
    bitree_t *pre = NULL;

    push_linkstack(s, root);
    while (!is_empty_linkstack(s)) {
        cur = get_top_data(s);
        if ((cur->lchild == NULL && cur->rchild == NULL) ||
            (pre != NULL && (pre == cur->lchild || pre == cur->rchild))) {
            printf("(%d: %c) ", cur->n, cur->data);
            pop_linkstack(s);
            pre = cur;
        } else {
            if (cur->rchild != NULL)
                push_linkstack(s, cur->rchild);
            if (cur->lchild != NULL)
                push_linkstack(s, cur->lchild);
        }
    }
    free(s);
}
