#include "head.h"

//
// Created by SlybootsLion on 2022/8/29.
//
int main() {
    linknode_t *head = NULL;
    int n = 0, i = 0, ret = 0;
    datatype_t data;
    head = create_empty_linklist();

    printf("please input you want insert data number: ");
    scanf("%d", &n);

    printf("please input %d data :", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &data);
        insert_order_linklist(head, data);
    }

    printf_data_linklist(head);

    return 0;
}
