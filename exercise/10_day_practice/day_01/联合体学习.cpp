#include "day01.h"

// 联合体内所有成员，公用同一内存位置，其长度为联合中最大的变量长度
union myun
{
	struct
	{
		int x;
		int y;
		int z;
	} u;
	int k;
} a;

void day01::day01_3() {
	a.u.x = 4;
	a.u.y = 5;
	a.u.z = 6;
	a.k = 0; // 所以，这里会覆盖掉x的赋值
	printf("%d %d %d %d\n", a.u.x, a.u.y, a.u.z, a.k);
}
