#include "chapter03.h"

void main03__11_7(){
	float unit = 2.54;
	printf("Enter height in inches: ");
	float height;
	scanf("%f", &height);
	printf("Your height (cm) is: %.2f", height * unit);
}
