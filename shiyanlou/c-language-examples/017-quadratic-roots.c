#include <stdio.h>
#include <math.h>

/*
求一元二次方程：ax2+bx+c=0 的根。
输入三个实数a,b,c的值，且a不等于0。

引用了math库，编译的时候需要加 -lm 参数
gcc -o main.out 017-quadratic-roots.c -lm
 */
int main()
{
  float a, b, c;
  printf("输入方程的三个系数：");
  scanf("%f%f%f", &a, &b, &c);

  if (a != 0)
  {
    float d = sqrt(b * b - 4 * a * c);
    float x1 = (-b + d) / (2 * a);
    float x2 = (-b - d) / (2 * a);
    if (x1 < x2)
      printf("%0.2f %0.2f\n", x2, x1);
    else
      printf("%0.2f %0.2f\n", x1, x2);
  }

  return 0;
}
