#include "chapter03.h"

void main03__11_6() {
	double one_quart = 950, molecular_mass = 3.0e-23;
	printf("enter quart number: ");
	double water;
	scanf("%lf", &water);
	printf("The molecular numbers for %.2lf quarts of water are: %le", water, water * one_quart / molecular_mass);
}
