//
// Created by SlybootsLion on 2022/9/3.
//
#include "bitree.h"

bitree_t *create_binatry_tree(int n) {
    bitree_t *root = NULL;
    root = (bitree_t *) malloc(sizeof(bitree_t));
    memset(root, 0, sizeof(bitree_t));

    root->n = n;
    root->lchild = root->rchild = NULL;

    printf("Input %d node data: ", n);
    scanf("%c", &(root->data));

    while (getchar() != '\n');

    if (2 * n <= N)
        root->lchild = create_binatry_tree(2 * n);

    if (2 * n + 1 <= N)
        root->rchild = create_binatry_tree(2 * n + 1);

    return root;
}
