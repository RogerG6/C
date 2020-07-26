/* Date：2020/3/16
 * 7-2：编写一个程序，以合理的方式打印任何输入。该程序至少能够根据用户的习惯以八进制或十六进制打印非图形字符，并截断长文本行
 */
#include <stdio.h> 
#include <ctype.h>

#define MAXLEN 10
#define OCT		6

int inc(int pos, int n);

main(void)
{
	int c, pos;
	
	pos = 0;		//一行中的位置 
	while ((c = getchar()) != EOF)
		if (iscntrl(c) || c == ' ')
		{			//non graphic char
			pos = inc(pos, OCT);
			printf(" \\%03o ", c); 
			
			if (c == '\n')
			{
				putchar('\n');
				pos = 0;
			}
		}
		else		//graphic char
		{
			pos = inc(pos, 1);
			putchar(c);
		}
	
	return 0;
}

int inc(int pos, int n)
{
	if (pos + n < MAXLEN)
		return pos + n;
	else
	{
		putchar('\n');
		return n;
	}
}

