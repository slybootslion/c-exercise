#include "chapter06.h"

/*
1．编写一个程序，创建一个包含26个元素的数组，并在其中储存26个小写字母。然后打印数组的所有内容。
 * */
void q6_1() {
	const int SIZE = 26;
	char c[SIZE];
	char ch = 'a';
	for (int i = 0; i < SIZE; ++i, ch++)
		c[i] = ch;
	for (int i = 0; i < SIZE; ++i)
		printf("char c[%d] = %c\n", i, c[i]);
}

/*
2．使用嵌套循环，按下面的格式打印字符：
$
$$
$$$
$$$$
$$$$$
 * */
void q6_2() {
	for (int i = 0; i < 5; ++i) {
		for (int j = 0; j < i + 1; ++j) {
			printf("$");
		}
		putchar('\n');
	}
}

/*
3．使用嵌套循环，按下面的格式打印字母：
F
FE
FED
FEDC
FEDCB
FEDCBA
注意：如果你的系统不使用ASCII或其他以数字顺序编码的代码，可以把字符数组初始化为字母表中的字母：
char lets[27]="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
然后用数组下标选择单独的字母，例如1ets［0］是＇A＇，等等。
 * */
void q6_3() {
	for (int i = 0; i < 6; ++i) {
		char ch = 'F';
		for (int j = 0; j < i + 1; ++j, ch--) {
			printf("%c", ch);
		}
		putchar('\n');
	}
}

/*
4．使用嵌套循环，按下面的格式打印字母：
A
BC
DEF
GHIJ
KLMNO
PQRSTU
如果你的系统不使用以数字顺序编码的代码，请参照练习3的方案解决。
 * */
void q6_4() {
	char ch = 'A';
	for (int i = 0; i < 6; ++i) {
		for (int j = 0; j < i + 1; ++j, ch++)
			printf("%c", ch);
		putchar('\n');
	}
}

/*
5，编写一个程序，提示用户输入大写字母。使用嵌套循环以下面金字塔型的格式打印字母：
A
ABA
ABCBA
ABCDCBA
ABCDEDCBA
打印这样的图形，要根据用户输入的字母来决定。例如，上面的图形是在用户输入E后的打印结果。提示：用外层循环处理行，每行使用3个内层循环，
分别处理空格、以升序打印字母、以降序打印字母。
 如果系统不使用ASCI或其他以数字顺序编码的代码，请参照练习3的解决方案。
 * */
void q6_5() {
	char ch;
	printf("enter capital letters:");
	scanf("%c", &ch);
	int len = ch - 'A' + 1;
	for (int i = 0; i < len; ++i) {
		char t = 'A';
		for(int j = 0; j < len - i - 1; j++)
			putchar(' ');
		for(int j = 0; j < i; j++, ++t)
			printf("%c", t);
		for(int j = 0; j < i + 1; j++, --t)
			printf("%c", t);
		putchar('\n');
	}
}

void chapter06() {
//	q6_1();
//	q6_2();
//	q6_3();
//	q6_4();
	q6_5();
}
