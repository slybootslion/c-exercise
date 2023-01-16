#include "chapter02.h"

/*7.许多研究表明，微笑益处多多。编写一个程序，生成以下格式的输
出：
Smile!Smile!Smile!
Smile!Smile!
Smile!
该程序要定义一个函数，该函数被调用一次打印一次“Smile!”，根据程
序的需要使用该函数。*/
void print_smail(int count) {
	for (int i = 0; i < count; i++)
		printf("Smile!");
	putchar('\n');
}
void main02__12_7() {
	print_smail(3);
	print_smail(2);
	print_smail(1);
}
