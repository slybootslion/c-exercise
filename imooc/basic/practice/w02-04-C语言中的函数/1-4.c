/*
定义全局变量 global_data = 0;
 设计无参数的函数global_calc()，在这个函数内部要求用户从键盘输入一个数据赋值给global_data，然后要求该函数输出，从1~global_data之间所有能被7整除的数据。

main函数来调用以下global_data这个函数。
*/
#include "stdio.h"

int global_data = 0;

void global_calc() {
    printf("input integer number:\n");
    scanf("%d", &global_data);

    while (global_data >= 7) {
        if (global_data % 7 == 0)
            printf("%d\t", global_data);
        global_data--;
    }
    printf("\n");
}

int main() {
    global_calc();
    return 0;
}
