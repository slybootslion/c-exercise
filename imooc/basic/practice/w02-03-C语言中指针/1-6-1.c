#include <stdio.h>

/*
 定义一个数组
int a[5] = {0};
要求大家从键盘上输入数据给数组赋值。
然后定义一个指针int *p_max要求它保存最大值的地址。
然后通过*p_max输出最大值。
 * */

int main() {
    int a[5];
    int *p_max = a;
    int len = sizeof(a) / sizeof(a[0]);
    printf("input %d integer number:\n", len);
    for (int i = 0; i < len; ++i)
        scanf("%d", &a[i]);
    for (int i = 0; i < len; ++i) {
        if (i == 0)
            *p_max = a[0];
        *p_max < a[i] && (*p_max = a[i]);
    }
    printf("p_max = %d\n", *p_max);
    return 0;
}
