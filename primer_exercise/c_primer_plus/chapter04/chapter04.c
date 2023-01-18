#include "chapter04.h"

// 我有点后悔用前面两章的方式来写题，太麻烦了，还要写好几个文件，这章开始简化，如果后面有需要拆分的再改回去。

/*
 1.编写一个程序，提示用户输入名和姓，然后以“名,姓”的格式打印出来。
 * */
void q4_1() {
	printf("Enter last and first name: ");
	char first[40], last[40];
	scanf("%s %s", last, first);
	printf("%s,%s\n", last, first);
}

/*
2.编写一个程序，提示用户输入名和姓，并执行一下操作：
a.打印名和姓，包括双引号；
b.在宽度为20的字段右端打印名和姓，包括双引号；
c.在宽度为20的字段左端打印名和姓，包括双引号；
d.在比姓名宽度宽3的字段中打印名和姓。
 * */
void q4_2() {
	printf("Enter last and first name: ");
	char first[40], last[40];
	scanf("%s %s", last, first);
	int len = (int)(strlen(last) + strlen(first) + 3);
	printf("your name is: \"%s %s\"\n", last, first);
	printf("your name is: \"%20s %s\"\n", last, first);
	printf("your name is: \"%s %-20s\"\n", last, first);
	printf("your name is: \"%*s %s\"\n", len, last, first);
}

/*
3.编写一个程序，读取一个浮点数，首先以小数点记数法打印，然后以
指数记数法打印。用下面的格式进行输出（系统不同，指数记数法显示的位
数可能不同）：
a.输入21.3或2.1e+001；
b.输入+21.290或2.129E+001；
*/
void q4_3() {
	double a=0;
	printf("输入一个小数:");
	scanf("%lf",&a);
	printf("a.输入%.1lf或%.1e\n",a,a);
	printf("b.输入%+.3lf或%.3E\n",a,a);
}

// 后面暂时不写了，一个printf有啥好写的

void chapter04() {
//	q4_1();
//	q4_2();
	q4_3();
}
