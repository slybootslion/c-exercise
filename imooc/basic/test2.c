#include <stdio.h>

int main()
{
  unsigned char a = 0x58; // 0101 1000
  unsigned char b = 0xd7; // 1101 0111
                          // ~ 0010 1000
  unsigned char c = 0;

  c = a & b; // 0101 0000
  c = a | b; // 1101 1111
  c = (a & ~b) ^ 0xf1;// ~b 0010 1000
                      // a & b 0000 1000
                      // 0xf1 1111 0001
                      // ^ 1111 1001
                      // ()10 -> 1 + 0 + 0 + 8 + 16 + 32 +  64 + 128 = 249
  printf("%d", c); // 249

  return 0;
}
