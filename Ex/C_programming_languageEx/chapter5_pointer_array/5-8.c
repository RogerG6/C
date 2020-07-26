/* Date：2020/3/9 
 * 5-8：函数day_of_year和month_day中没有进行错误检查，请解决该问题
 */ 
# include <stdio.h>

const static char daytab[2][13] = {
	{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
	{0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
};

int day_of_year(int year, int month, int day)
{
	int i, leap;
	
	if (year < 1)
		return -1;
	if (month < 1 || month > 12)
		return -1;
	
	/* 判断是否是闰年 */ 
	leap = (year % 4 == 0 && year % 100 == 0) || (year % 400 == 0);
	if (day > daytab[leap][month])
		return -1;
		
	for (i = 1; i < month; i++)
		day += daytab[leap][i];
	
	return day; 
}

int month_day(int year, int yeardays, int *pmonth, int *pday)
{
	int i, leap;
	
	if (year < 1)
		return -1;
	
	/* 判断是否是闰年 */ 
	leap = (year % 4 == 0 && year % 100 == 0) || (year % 400 == 0);
	if (yeardays > (leap ? 366 : 365))	
		return -1;
	
	for (i = 1; i <= 12 && yeardays > daytab[leap][i]; i++)
		yeardays -= daytab[leap][i];
	
	*pmonth = i;
	*pday = yeardays;
	return 0;
}

int main(void)
{
	int year, month, day, yeardays, response, err = -1;
	
	while (1)
	{
		printf("\n1. days of year\n2. month day\nEnter your choice: ");
		scanf("%d", &response);
		
		if (response == 1)
		{
			while (err < 0){
				printf("Year, month, day: ");
				scanf("%d%d%d", &year, &month, &day);
				if ((err = day_of_year(year, month, day)) < 0)
					printf("Enter the right values\n");
			}
			printf("%d/%d/%d is %d 's %d days\n", year, month, day, year, err);
		}
		else
		{
			while (err < 0){
				printf("Year, day: ");
				scanf("%d%d", &year, &yeardays);
				err = month_day(year, yeardays, &month, &day);
				if (err <0)
					printf("Enter the right values\n");
			}
			printf("%d 's %d days is %d/%d\n", year, yeardays, month, day);
		}
		err = -1;	
	}
	
	return 0;
}
