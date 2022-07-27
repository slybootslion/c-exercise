#include <stdio.h>

int main()
{
		int data = 0;
		printf("please input a data:");
		scanf("%d", &data);

		printf("data > 30 = %d\n", data > 30);
		printf("data == 30 = %d\n", data == 30);

		printf("==================\n");

		printf("data = 800 : %d\n", data = 800);
		printf("data != 800 : %d\n", data != 800);

		printf("==================\n");

		printf("10 < data < 20 : %d\n", 10 < data < 20);

		return 0;
}
