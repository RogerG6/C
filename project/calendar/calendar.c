/* Date：2020/3/19
 * Author：rogerg6
 * Function: win环境下的简易日历小程序
 * 			 其中的颜色设置仅仅在win下的控制台可用
 */

#include <stdio.h>
#include <windows.h>
#include <ctype.h>
//#include <stdlib.h>


int daytab[2][13] = {
	{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
	{0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};
char title[] = "MON    TUE    WEN    THR    FRI    SAT    SUN";
const int by = 2020, bm =6;		// base 2020/6/1 周一

int days_of_year(int year, int month);
int all_days(int year);
void calendar(int year, int month, int day);
int getalpha();

int main(void)
{
	int year, month, day;
	int c;
	
	do{
		//printf("%d\n", c == '\n');
		printf("\n============================\nEnter year, month, day(y/m/d):");
		while (3 != scanf("%d/%d/%d", &year, &month, &day))
			printf("Usage: 2020/6/1\nInput again: ");
		calendar(year, month, day);
		printf("\nContinue? (q to quit): ");
	}while ((c = getalpha()) != 'q');
	
	return 0;
}

/* 得到输入流中第一个alpha char */
int getalpha()
{
	int c;
	while (!isalpha(c = getchar()))
		;
	return c;
}

/* 日历的核心函数 */
void calendar(int year, int month, int day)
{
	long delta = 0;
	int i, afy, afm;
	int after, leap, week;
	
	leap = ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) ? 1 : 0;
	after = (year > by || (year == by && month > bm)) ? 1 : 0;
	
	// 计算相关的天数, 由天数得到周几
	if (after){			// 在base之后
		afy = year;
		afm = month;
		for (delta = days_of_year(afy, afm); --afy >= by; ){
			delta +=  all_days(afy);
		}
		delta -= days_of_year(by, bm);
		week = delta % 7;
	}
	else{				//在base之前 或 就是base
		afy = by;
		afm = bm;
		for (delta = days_of_year(by, bm); --afy >= year; ){
			delta +=  all_days(afy);
		}
		delta -= days_of_year(year, month);
		week = (7 - delta % 7) % 7;
	}
	
	//printf("week = %d\n", week + 1);
	// 打印日历
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);	// white
	printf("\n%*c%d/%d\n%s\n", 19, ' ', year, month, title);
	if (week)
		printf("%*c", week * 7, ' ');
	week += 1;
	for (i = 0; i < daytab[leap][month]; week++, i++){
		if (i + 1 == day){
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0xf0);	// black font white back
			printf("%3d",  i + 1);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);	// white
			printf("    ");
		}	
		else{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);	// white font black back
			printf("%3d    ",  i + 1);
		}
		if (week % 7 == 0)
			putchar('\n');
	}
}

/* 计算从年初到month月前的总天数
 * eg. month = 4, days = 1+2+3
 */
int days_of_year(int year, int month)
{
	int leap = ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) ? 1 : 0;
	int days = 0;
	
	while (--month)
		days += daytab[leap][month];
	return days;
}

/* 计算一年的总天数 */
int all_days(int year)
{
	int leap = ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) ? 1 : 0;
	return leap ? 366 : 365;
}