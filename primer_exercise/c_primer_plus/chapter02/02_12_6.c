#include "chapter02.h"

/*6.编写一个程序，创建一个整型变量toes，并将toes设置为10。程序中还
要计算toes的两倍和toes的平方。该程序应打印3个值，并分别描述以示区
分。*/
void main02_12_6() {
	int toes = 10;
	int toes2 = toes * 2;
	int toes_square = toes * toes;
	printf("toes：%d\n", toes);
	printf("toes的两倍：%d\n", toes2);
	printf("toes的平方：%d\n", toes_square);
}
