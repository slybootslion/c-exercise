//
// Created by SlybootsLion on 2022/8/29.
//
#include "head.h"

int main() {
    linknode_t *head = create_empty_linklist();
    int arr[] = {1, 5, 3, 7, 9};

    for (int i = 0; i < 5; ++i)
        insert_order_linklist(head, arr[i]);

    printf_data_linklist(head);

    return 0;
}
