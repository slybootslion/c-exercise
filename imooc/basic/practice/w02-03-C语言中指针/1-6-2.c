#include <stdio.h>

/*
unsigned int data = 0x11223344;
unsigned short *q = NULL;
unsigned short t1 = 0;
unsigned short t2 = 0;

(1)要求指针q保存data的地址.
(2)要求利用q读取data的低2个字节赋值給t1 ===>0x3344
要求利用q读取data的高2个字节赋值給t2 ===>0x1122
(3)输出t1和 t2 的和与差
*/

int main() {
    unsigned int data = 0x11223344;
    unsigned short *q = NULL;
    unsigned short t1 = 0;
    unsigned short t2 = 0;

    q = (unsigned short *) &data;
    t1 = *q;
    q++;
    t2 = *q;

    printf("t1 + t2 = %#x\n", t1 + t2);
    printf("t1 - t2 = %#x\n", t1 - t2);

    return 0;
}
