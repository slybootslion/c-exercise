//
// Created by SlybootsLion on 2022/9/3.
//
#include "bitree.h"

int main () {
    bitree_t *root;
    root = create_binatry_tree(1);

    printf("create is successful!\n");

    printf("pre_order: ");
    pre_order(root);
    printf("\n");

    printf("in_order: ");
    in_order(root);
    printf("\n");

    printf("post_order: ");
    post_order(root);
    printf("\n");
    
    return 0;
}
