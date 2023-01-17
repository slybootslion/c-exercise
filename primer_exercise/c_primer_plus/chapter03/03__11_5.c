#include "chapter03.h"

void main03__11_5() {
	printf("enter age(number): ");
	double age;
	scanf("%lf", &age);
	double year_second = 3.156e7; // 31560000
	printf("your age second is: %lf", year_second * age);
}
