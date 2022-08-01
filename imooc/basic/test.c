#include <stdio.h>

int main()
{
    unsigned char a = 0x58; // 0101 1000
    unsigned char b = 0xd7; // 1101 0111
    unsigned char c = 0;
    c = a & b;
    //                         0101 0000
    printf("%x\n", c); // 0x50
    c = a | b;
    //                         1101 1111
    printf("%x\n", c); // 0xdf
    c = (a & ~b) ^ 0xf1; // f1 1111 0001
    //                      ~b 0010 1000
    //                      &a 0000 1000
    //                      ^  1111 1001
    printf("%x\n", c); // 0xf9
    return 0;
}
