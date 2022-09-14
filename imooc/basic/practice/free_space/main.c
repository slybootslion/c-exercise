//
// Created by ubuntu on 22-8-31.
//

#include "linklist.h"

int main() {
    linklist_t *head = NULL;
    head = create_empty_linklist();

    datatype_t data;
    int n = 0, i = 0;

    printf("please input data number you want to insert: ");
    scanf("%d", &n);

    printf("please input %d data: ", n);

    for (i = 0; i < n; i++) {
        scanf("%d", &data);
        insert_tail_linklist(head, data);
    }

    print_data_linklist(head);

    sort_linklist(head);

    print_data_linklist(head);
    return 0;
}
