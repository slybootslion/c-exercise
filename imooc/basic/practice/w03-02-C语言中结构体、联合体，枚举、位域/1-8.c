//
// Created by SlybootsLion on 2022/8/19.
//

#include <stdio.h>

/*
typedef struct
{
    unsigned char Red;
    unsigned char Green;
    unsigned char Blue;
}RGB_t;

typedef union
{
    RGB_t  rgb;
    unsigned int value;
}PIX_t;

int main()
{
    //1. 定义一个PIX_t类型的变量，然后定义三原色分别为0X11、0X22、0X33，
    //2. 不做任何处理，直接打印value。
    //3.观察结果
}
 * */

typedef struct {
    unsigned char Red;
    unsigned char Green;
    unsigned char Blue;
} RGB_t;

typedef union {
    RGB_t rgb;
    unsigned int value;
} PIX_t;

int main() {
    PIX_t p;
    p.rgb.Red = 0x11;
    p.rgb.Green = 0x22;
    p.rgb.Blue = 0x33;
    printf("%#x\n", p.value);
    return 0;
}
