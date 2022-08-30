//
// Created by SlybootsLion on 2022/8/30.
//
#include "head.h"

int main() {

    loopnode_t *head = NULL;
    int n = 0;
    datatype_t data;
    head = create_empty_looplist();

    printf("please input you want insert data number: \n");
    scanf("%d", &n);

    printf("please input %d data: ", n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &data);
        insert_head_looplist(head, data);
    }

    printf_data_looplist(head);

    return 0;
}
