#include "chapter03.h"

void main03__11_8() {
	float pint = 0.5;
	float ounce = 8;
	float tablespoon = 2 * ounce;
	float teaspoon = 3 * tablespoon;


	float cup;
	printf("Enter number of cups: ");
	scanf("%f", &cup);
	printf("pint: %.2f\n", pint * cup);
	printf("ounce: %.2f\n", ounce * cup);
	printf("tablespoon: %.2f\n", tablespoon * cup);
	printf("teaspoon: %.2f\n", teaspoon * cup);
}
