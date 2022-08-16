#include <stdio.h>

/*
int data1 = 10, data2 = 20;
int *p = NULL;
int *q = NULL;

1.要求实现p和q分别保存data1和data2的地址.
2.利⽤p和q交换data1和data2的值
3.输出data1和data2的值
* */

int main() {
    int data1 = 10, data2 = 20;
    int *p = NULL;
    int *q = NULL;

    p = &data1;
    q = &data2;

    int temp = *p;
    *p = *q;
    *q = temp;

    printf("data1 = %d\n", data1);
    printf("data2 = %d\n", data2);

    return 0;
}
