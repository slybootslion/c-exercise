//
// Created by SlybootsLion on 2022/8/29.
//
#include "head.h"

int main() {
    linknode_t *head = create_empty_linklist();
    int arr[] = {1, 5, 3, 7, 9, 5, 8, 5, 3};

    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); ++i)
        insert_order_linklist(head, arr[i]);

    printf("删除前：");
    printf_data_linklist(head);
    delete_data_linklist(head, 3);
    printf("删除后：");
    printf_data_linklist(head);

    return 0;
}
