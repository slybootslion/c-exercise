#include "chapter05.h"

/*
1 ．编写一个程序。将用分钟表示的时间转换成以小时和分钟表示的时间。使用 #define 或者 const 来创建一个代表 60 的符
 号常量。使用 while 循环来允许用户重复键入值，并且当键入一个小于等于 0 的时间时终止循环。
 * */
void q5_1() {
	const int cardinality = 60;
	int count_minute;
	while (1) {
		printf("enter minutes: ");
		scanf("%d", &count_minute);
		if (count_minute <= 0) break;
		int m = count_minute % cardinality;
		int h = count_minute / cardinality;
		printf("%d hour, %d minute\n", h, m);
	}
}

/*
2.编写一个程序，提示用户输入一个整数，然后打印从该数到比该数大10的所
 有整数（例如，用户输入5，则打印5~15的所有整数，包括5和15）。要求打
 印的各值之间用一个空格、制表格或者换行符分开。
 * */
void q5_2() {
	int n;
	const int count = 10;
	printf("enter a integer number: ");
	scanf("%d", &n);
	for (int i = 0; i <= count; ++i)
		printf("%d ", n + i);
	putchar('\n');
}

/*
3.编写一个程序，提示用户输入天数，然后将其转换成周数和天数。例如，用户输入18，则转换成2周4天。以下面的格式展示结果。
18 days are 2 weeks, 4 days.
通过while循环让用户重复输入天数，当用户输入一个非正数时，循环结束。
 * */
void q5_3() {
	printf("Enter the number of days: ");
	const int cardinality = 7;
	while (1) {
		int days;
		scanf("%d", &days);
		if (days <= 0) break;
		int w = days / cardinality;
		int d = days % cardinality;
		printf("%d days are %d weeks, %d days.\n", days, w, d);
	}
}

/*
4.编写一个程序，提示用户输入身高（单位：厘米），并分别以厘米和英寸为单位显示该值，允许有小数部分。程序能让用户重复输入身高，直到用户输入一个非正值。
其示例输出如下：
Enter a height in centimeters: 182
182.0 cm = 5 feet, 11.7 inchs
Enter a height in centimeters(<=0 to quit): 168.7
168.7 cm = 5 feet, 6.4 inchs
Enter a height in centimeters(<=0 to quit): 0
bye
 * */
void q5_4() {
	printf("Enter a height in centimeters: ");
	float height;
	const float feet = 2.54, inch = 30.48;
	while (1) {
		scanf("%f", &height);
		if (height <= 0) {
			printf("bye");
			break;
		}
		int f = (int)(height / inch);
		float i = (height - (float)f * inch) / feet;
		printf("%.2f cm = %d feet, %.1f inchs\n", height, f, i);
	}
}

void chapter05() {
//	q5_1();
//	q5_2();
//	q5_3();
	q5_4();
}
