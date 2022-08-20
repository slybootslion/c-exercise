//
// Created by SlybootsLion on 2022/8/20.
//

#include <stdio.h>
#include <string.h>

#define LE_YEAR 1

int Isleap(int year) {
    return year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
}

int max_day(int year, int month) {
    int months[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (Isleap(year))
        months[1] = 29;
    return months[month];
}

int Total_day(int year, int month, int day) {
    int total = 0;
    for (int i = 0; i < month - 1; ++i)
        total += max_day(year, i);
    total += day;
    return total;
}

int get_week(int year, int month, int day) {
    return (day + 2 * month + 3 * (month + 1) / 5 + year + year / 4 - year / 100 + year / 400 + 1) % 7;
}

char *weekday(int year, int month, int day) {
    int W = get_week(year, month, day);
    char *weeks[7] = {"星期天", "星期一", "星期二", "星期三", "星期四", "星期五", "星期六"};
    return weeks[W];
}

void display_month(int year, int month, int day) {
    printf("\t\t%d年%d月\n", year, month);
    printf("SUN\tMON\tTUE\tWED\tTHU\tFRI\tSAT\n");

    int first_W = get_week(year, month, 1);
    for (int i = 0; i < first_W; ++i)
        putchar('\t');

    int limit_day = max_day(year, month - 1);
    for (int i = 0; i < limit_day; ++i) {
        printf("%d\t", i + 1);
        if ((first_W + i + 1) % 7 == 0)
            putchar('\n');
    }
    putchar('\n');
}


int main() {
    int year, month, day;

    printf("please input [year month day]: \n");
    scanf("%d%d%d", &year, &month, &day);

    if (month < 1 || month > 12 || day < 1 || day > 31) {
        printf("Input date is error!\n");
        return -1;
    }

    int ret = Isleap(year);
    ret == LE_YEAR ?
    printf("%d年%d月%d日是闰年\n", year, month, day) :
    printf("%d年%d月%d日不是闰年\n", year, month, day);

    ret = Total_day(year, month, day);
    printf("%d年%d月%d号是这一年的第%d天。\n", year, month, day, ret);

    static char s[3];
    strcpy(s, weekday(year, month, day));
    printf("%d年%d月%d日是%s\n", year, month, day, s);

    display_month(year, month, day);

    return 0;
}

/*
一、C语言实现一个日历的小程序

<1>判断闰年
1、main()函数从键盘输入一个三个数，分别是年，月，日（例如,2015 3 4），

2、设计一个Isleap()函数，判断从键盘输入的日期，是不是闰年。
若是闰年的话，主函数打印

2015年3月4日是闰年，否则

打印"2015年3月4日不是闰年"

提示：
闰年满足以下的条件：
(1)能被4整除并且不能被100整除为闰年（例如,2004年是闰年）
(2)能被400整除的也是闰年（例如 2000年也是闰年）

注意：以上条件只要满足一条，则说明该年为闰年。


<2>判断天数
在上面的基础上添加如下信息

再设计一个Total_day()函数，要求计算出该年的1月1号
到从键盘输入日期，已经过了多少天了？

（例如,2015年1月1号到2015年3月4号一共过了63天。）
思路：可设计一个函数max_day()计算1-2月的总天数 + 3月的天数
然后再main()函数中输出下列内容。

2015年1月1号是这一年的第63天。

提示：
1年有365/366天

若是普通年(365天)：31 28 31 30 31 30 31 31 30 31 30 31
若是闰年(365天)：  31 29 31 30 31 30 31 31 30 31 30 31

注：闰年二月多1天


<3>判断输入是日期是星期几？
设计一个display_week()函数，判断
输入的日期是星期几？

然后在该函数中输出该年是星期几？
例如；输入 : 2015 3 4
      输出 : 2015年3月4日是星期三。

提示：
这里可用《基姆拉尔森日期计算公式来算》
基姆拉尔森计算公式

W= (d + 2*m + 3*(m+1) / 5 + y + y / 4 - y / 100 + y / 400 + 1)%7

注：
<1>d表示天数，m表示月数，y表示年数，W表示星期几
<2>若是，输入的月数是1月或者2月的话，则要转换成上
   一年的十三月和十四月来计算。

例如：
输入2004-1-10，则应该换成2003-13-10来计算
输入2006-2-5，则应换算成2005-14-5来计算

<4>显示当月的日历
设计一个display_month()函数显示从键盘输入
该年当月的日历。

提示：
<1>日历第一天显示的是星期天，最后一天显示是星期六。
<2>每个月的1号是星期几？则前面要空几天。
   可调用display_week()函数来获得星期数。
<3>每月的月数如下：

若是普通年(365天)：31 28 31 30 31 30 31 31 30 31 30 31
若是闰年(365天)：  31 29 31 30 31 30 31 31 30 31 30 31

要求打印形式如下（可用\t为分隔符）：
               2015年5月
SUN    MON   TUE   WED    THU     FRI    SAT
                                    1      2
 3      4     5    6       7       8      9
 10    11    12    13     14       15     16
 17    18    19    20     21       22     23
 24    25    26    27     28       29     30
 31
 * */
