#include <stdio.h>
#include <ctype.h>
#include "calc.h"

int getop(char s[])
{
	int i, c;
	
	/* 跳过空白 */ 
	while ((c = getch()) == ' ' || c == '\t')	
		;
	
	i = 0;
	/* 非数字 */ 
	if (!isdigit(c) && c != '.' && c != '-')
		return c;
		
	/* 负数 */ 
	if (c == '-') 
	{		
		if (isdigit(c = getch()) || c == '.')
			s[i++] = '-';
		else
		{
			if (c != EOF)
			{		
				ungetch(c) ;
				return '-';
			}
		}	
	}
	
	
	/* 整数 */
	if (isdigit(c))
	{
		do
			s[i++] = c;
		while (isdigit(c = getch()));
	}
			
	/* 小数 */ 
	if (c == '.')
	{
		do
			s[i++] = c;
		while (isdigit(c = getch()));
	}
	
	s[i] = '\0';
	if (c != EOF)
		ungetch(c);
	
	return NUMBER;
}

