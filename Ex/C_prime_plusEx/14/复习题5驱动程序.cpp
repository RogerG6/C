#include <stdio.h>
int days(struct month * p, int num);

 struct month{
		char name[10];
		char shortname[4];
		int days;
		int number;
	}; 
	

int main(void)
{
	int n;
	struct month year[12] = {
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
	scanf("%d", &n);
	printf("there are %d days til %d month\n", days(year, n), n);
	
	return 0;
}
int days(struct month * p, int num)
	{
		int tot = 0;
		for (; p < p+12; p++)
		{
			tot += p->days;
			if (num == p->number)
				break;
		}
		return tot;
	}
