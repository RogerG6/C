#include <stdio.h>
# include <string.h>
int days(char * m);

 struct month{
		char name[10];
		char shortname[4];
		int days;
		int number;
	}; 
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

int main(void)
{
	char m[10];

	scanf("%s", m);
	printf("there are %d days til %s month\n", days(m), m);
	
	return 0;
}
int days(char * m)
	{
		int i;
		int tot = 0;
		for (i = 0; i < 12; i++)
		{
			tot += year[i].days;
			if (strcmp(m, year[i].name) == 0)
				break;
		}
		if (i == 12)
			return -1;
		else	
			return tot;
	}
