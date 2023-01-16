#include "chapter03.h"

void main03_3_8() {
	printf("Type int has a size of %zd bytes.\n", sizeof(int)); // 4 bytes
	printf("Type char has a size of %zd bytes.\n", sizeof(char)); // 1 byte
	printf("Type long has a size of %zd bytes.\n", sizeof(long)); // 8 bytes
	printf("Type long long has a size of %zd bytes.\n", sizeof(long long)); // 8 bytes
	printf("Type double has a size of %zd bytes.\n", sizeof(double)); // 8 bytes
	printf("Type long double has a size of %zd bytes.\n", sizeof(long double)); // 16 bytes
}
