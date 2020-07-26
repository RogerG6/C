#include <stdio.h>
# include <string.h>
int daynum(int day, char * month, int year);
void eatline(void);
int is_leapy(int year)  ;

const char * day31 = "janury march may july august october december";
const char * day30 = "april june septeber november";

 struct month{
		char name[10];
		char shortname[4];
		int days;
		int number;
	}; 
struct month oneyear[12] = {
		{"janury", "jan", 31, 1}, 
		{"feburary", "feb", 28, 2}, 
		{"march", "mar", 31, 3}, 
		{"april", "apr", 30, 4}, 
		{"may", "may", 31, 5}, 
		{"june", "jun", 30, 6},
		{"july", "jul", 31, 7}, 
		{"august", "aug", 31, 8}, 
		{"septeber", "sep", 30, 9}, 
		{"october", "oct", 31, 10}, 
		{"november", "nov", 30, 11},
		{"december", "dec", 31, 12}
	};	

int main(void)
{
	char month[10];
	int year;
	int day, days;
	
	do
	{
		printf("Enter day/month/year:");
		scanf("%d %s %d", &day, month, &year);
		days =  daynum(day, month, year);
		eatline();
		if (days == -1)
			continue;
		printf("there are %d days til %d %s %d\n", days, day, month, year);
	} while (1);
	return 0;
}

void eatline(void)
{
	while (getchar() != '\n')
		continue;
}

int daynum(int day, char * month, int year)
	{
		int i;
		int tot = 0;

		if (is_leapy(year))
			oneyear[1].days = 29;
		
		if (strstr(day31, month) != NULL)   //判断是否是31天的月份 
		{
				putchar('a');
			if (! (day > 0 && day < 32))
			
				return -1;
		}
		if (strstr(day30, month) != NULL)   //判断是否是30天的月份 
		{
			if (! (day > 0 && day < 31))
				return -1;
		}
		if (strcmp(month, oneyear[1].name) == 0)    //判断是否是2月份 
		{
			if (! (day > 0 && day <= oneyear[1].days))
				return -1;
		}
		
			
		for (i = 0; i < 12; i++)
		{
			if (strcmp(month, oneyear[i].name) == 0)
				break;
			tot += oneyear[i].days;
		}
		
		return tot + day;
	}
	
int is_leapy(int year)  //判断是否为闰年 
{
	if (year % 400 == 0)
		return 1;
	else if (year % 4 == 0)
	{
		if (year % 100 != 0)
			return 1;
		else
			return 0;
	}
	else
		return 0;
}
