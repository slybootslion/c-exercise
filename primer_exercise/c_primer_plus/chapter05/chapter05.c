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

/*
5.修改程序addemup.c（程序清单5.13） ， 你可以认为addemup.c是计算20天里赚多少钱的
 程序（假设第1天赚$1、 第2天赚$2、 第3天赚$3， 以此类推） 。 修改程序，使其可以与用户
 交互， 根据用户输入的数进行计算（即，用读入的一个变量来代替20） 。
 * */

void q5_5() {
	printf("enter the number of earning days you want to calculate: ");
	int days;
	scanf("%d", &days);
	if (days <= 0) return;
//	int count = 0;
//	for (int i = 0; i < days; ++i)
//		count += (i + 1);
	// 也可以用数学公式计算
	int count = days * (days + 1) / 2;
	printf("earn $%d in %d days\n", count, days);
}

/*
6.修改编程练习5的程序， 使其能计算整数的平方和（可以认为第1天赚$1、 第2天
 赚$4、 第3天赚$9， 以此类推， 这看起来很不错） 。 C没有平方函数， 但是可
 以用n * n来表示n的平方。
 * */
void q5_6() {
	printf("enter the number of earning days you want to calculate: ");
	int days;
	scanf("%d", &days);
	if (days <= 0) return;
	int count = 0;
	for (int i = 0; i <= days; ++i)
		count += i * i;
	printf("earn $%d in %d days\n", count, days);
}

/*
7.编写一个程序，提示用户输入一个double类型的数，并打印该数的立方值。
 自己设计一个函数计算并打印立方值。main()函数要把用户输入的值传递给该函数。
 * */
double cube_func(double num) {
	return num * num * num;
}

void q5_7() {
	double num;
	printf("Enter a value of type double: ");
	scanf("%lf", &num);
	printf("enter value's cube is: %lf", cube_func(num));
}

/*
8.编写一个程序，显示求模运算的结果。把用户输入的第1个整数作为求模运算符的第2个运算对象，
 该数在运算过程中保持不变。用户后面输入的数是第1个运算对象。当用户输入一个非正值时，程序结
 束。其输出示例如下：
This program computes moduli.
Enter an integer to serve as the second operand: 256
Now enter the first operand: 438
438 % 256 is 182
Enter next number for first operand (<= 0 to quit): 1234567
1234567 % 256 is 135
Enter next number for first operand (<= 0 to quit): 0
Done
 * */
void q5_8() {
	int foperand, soperand, modulus;
	printf("This program computes moduli.\n");
	printf("Enter an integer to serve as the second operand: ");
	scanf("%d", &soperand);
	printf("Now enter the first operand: ");
	scanf("%d", &foperand);
	while (foperand > 0) {
		modulus = foperand % soperand;
		printf("%d %% %d is %d\n", foperand, soperand, modulus);
		printf("Enter next number for first operand (<= 0 to quit):");
		scanf("%d", &foperand);
	}
	printf("Done\n");
}

/*
9.编写一个程序，要求用户输入一个华氏温度。程序应读取double类型的值作为温度值，并把该值作为参数传递
 给一个用户自定义的函数Temperatures()。该函数计算摄氏温度和开氏温度，并以小数点后面两位数字的精度
 显示3种温度。要使用不同的温标来表示这3个温度值。下面是华氏温度转摄氏温度的公式：
摄氏温度 = 5.0 / 9.0 * (华氏温度 - 32.0)
开氏温标常用于科学研究，0表示绝对零，代表最低的温度。下面是摄氏温度转开氏温度的公式：
开氏温度 = 摄氏温度 + 273.16
Temperatures()函数中用const创建温度转换中使用的变量。在main()函数中使用一个循环让用户重复输入温
 度，当用户输入 q 或其他非数字时，循环结束。scanf()函数返回读取数据的数量，所以如果读取数字则返回1，
 如果读取q则不返回1。可以使用==运算符将scanf()的返回值和1作比较，测试两值是否相等。
 * */

void Temperatures(double fahrenheit) {
	const double a = 5.0, b = 9.0, c = 32.0, d = 273.16;
	const double celsius = a / b * (fahrenheit - c);
	const double kelvin = celsius + d;
	printf("fahrenheit is: %.2lf, celsius is: %.2lf, kelvin is: %.2lf.\n", fahrenheit, celsius, kelvin);
}

void q5_9() {
	double fahrenheit;
	printf("enter fahrenheit: ");
	while (scanf("%lf", &fahrenheit) == 1) {
		Temperatures(fahrenheit);
		printf("enter other fahrenheit or take 'q' to leave.\n");
	}
	printf("Done.");
}

void chapter05() {
//	q5_1();
//	q5_2();
//	q5_3();
//	q5_4();
//	q5_5();
//	q5_6();
//	q5_7();
//	q5_8();
	q5_9();

}
