/* Date：2020/3/10 
 * 5-9：用指针的方式代替数组下标方式改写函数day_of_year, month_day
 */ 
# include <stdio.h>
# define daytab(i, j) (*(*daytab + 13 * i + j))

static char daytab[2][13] = {
	{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
	{0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
};

int day_of_year(int year, int month, int day)
{
	int i, leap;
	char *p;
	
	if (year < 1)
		return -1;
	if (month < 1 || month > 12)
		return -1;
	
	/* 判断是否是闰年 */ 
	leap = (year % 4 == 0 && year % 100 == 0) || (year % 400 == 0);
	p = *(daytab + leap);
	if (day > *(p + month))
		return -1;
		
	while (--month)
		day += *++p;
	
	return day; 
}

int month_day(int year, int yeardays, int *pmonth, int *pday)
{
	int i, leap;
	char *p;
	
	if (year < 1)
		return -1;
	
	/* 判断是否是闰年 */ 
	leap = (year % 4 == 0 && year % 100 == 0) || (year % 400 == 0);
	p = *(daytab + leap);
	
	if (yeardays > (leap ? 366 : 365))	
		return -1;
	
	while (yeardays > *++p)
		yeardays -= *p;
	
	*pmonth = p - *(daytab + leap);
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
