#include "chapter03.h"

void main03_3_10() {
	float salary;
	printf("\aEnter your desired monthly salary:");
	printf(" $______\b\b\b\b\b\b\b");
	scanf("%f", &salary);
	printf("\n\t$%.2f a month is $%.2f a year.", salary, salary * 12);
	printf("\rGee!\n");
}
