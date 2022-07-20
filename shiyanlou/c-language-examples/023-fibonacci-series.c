#include <stdio.h>

// 输出指定数量的斐波那契数列
void print1(int n)
{
  long long t1 = 0, t2 = 1, nextTerm;
  printf("斐波那契数列：\n");
  for (int i = 0; i < n; i++)
  {
    printf("%lld ", t1);
    nextTerm = t1 + t2;
    t1 = t2;
    t2 = nextTerm;
  }
  printf("\n");
}

// 输出指定数字前的斐波那契数列
void print2(int n)
{
  long long t1 = 0, t2 = 1;
  printf("斐波那契数列：\n");
  printf("%lld %lld", t1, t2);
  long long nextTerm = t1 + t2;
  while (nextTerm <= n)
  {
    printf("%lld ", nextTerm);
    t1 = t2;
    t2 = nextTerm;
    nextTerm = t1 + t2;
  }
  printf("\n");
}

int main()
{
  int n;
  printf("输入一个正数：");
  scanf("%d", &n);

  print1(n);
  // print2(n);

  return 0;
}
