#include <stdio.h>

int main ()
{
	int a, b;
	printf("please input three integer:");
	scanf("%d%d", &a, &b);

	printf("a=%p, b=%p\n", &a, &b);
	return 0;
}
