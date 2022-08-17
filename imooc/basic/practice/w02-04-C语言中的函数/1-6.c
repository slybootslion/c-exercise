/*
//判断y是否是闰年,若是闰年,返回1，否则返回0
int do_leap(int y)
{

}

int main()
{
        int year;

        //1.要求用户从键盘输入1个年份赋值给year。

        //2.然后调用do_leap(year)函数,判断是否是闰年

        //3.利用ret变量接收返回值,若是闰年，输出"xx年是闰年",否则输出"xx年不是闰年"
}

*/

#include "stdio.h"

int do_leap(int y) {
    return y % 4 == 0 && y % 100 != 0 || y % 400 == 0;
}


int main() {
    int year;
    printf("input year number:\n");
    scanf("%d", &year);

    int result = do_leap(year);
    result ? printf("%d年是闰年\n", year) : printf("%d年不是闰年\n", year);

    return 0;
}
