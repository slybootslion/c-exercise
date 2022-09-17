#include <stdio.h>

void Move(int n, char src, char dest, char temp) {
  if (n == 0)
    return;
  else if (n == 1)
    printf("%c --> %c\n", src, dest);
  else {
    Move(n - 1, src, temp, dest);
    Move(1, src, dest, temp);
    Move(n - 1, temp, dest, src);
  }
}

int main(void) {
  Move(3, 'a', 'c', 'b');
  return 0;
}
