/* Date：2020/3/7 
 * 5-1：在上面的例子中，如果符号+或—后面紧跟的不是数字，getint函数将把符号视为数字0的有效表达式。
 *      修改该函数，将这种形式的+或－符号重新写回到输入流中。
 */ 
 
#include <stdio.h>
#include <ctype.h> 
#define MAX 100

int getint(int *pn);
char getch(void);
void ungetch(char c);


int main(void)
{
	int a[MAX] = {0}, i; 
	
	for (i = 0; i < MAX && getint(&a[i]) != EOF; i++) 
		; 
	
	/* 打印前20个数 */ 
	for (i = 0; i < 20; i++)
		printf("a[%d] = %d\n", i, a[i]);
	
	return 0;
}

int getint(int *pn)
{
	int c, sign;
	
	/* 跳过空白 */ 
	while (isspace(c = getch()))
		;
	
	/* 不是数字 */	
	if (!isdigit(c) && c != EOF && c != '+' && c != '-')
	{
		ungetch(c);
		return 0;
	}
	
	/* 处理符号 */ 
	sign = (c == '-' ? -1 : 1);
	if (c == '+' || c == '-')
	{
		if (!isdigit(c = getch()))
		{
			if (c != EOF)
				ungetch(c);
			*pn = 0;
			return c;
		}
	}
	
	/* 处理数字 */ 
	for (*pn = 0; isdigit(c); c = getch())
		*pn = 10 * *pn + (c - '0');
	*pn *= sign;
	
	if (c != EOF)
		ungetch(c);
	return c;
}


char buf[MAX];
int bufp = 0;

char getch(void)
{
	return (bufp > 0 ? buf[--bufp] : getchar());
}

void ungetch(char c)
{
	if (bufp > MAX)
		printf("Err: buf[MAX] is full\n");
	else
		buf[bufp++] = c;
}


/*
  -123
 +234
 +
        -
 567
789
a34
a[0] = -123
a[1] = 234
a[2] = 0
a[3] = 0
a[4] = 567
a[5] = 789
a[6] = 0
a[7] = 0
a[8] = 0
a[9] = 0
a[10] = 0
a[11] = 0
a[12] = 0
a[13] = 0
a[14] = 0
a[15] = 0
a[16] = 0
a[17] = 0
a[18] = 0
a[19] = 0

--------------------------------
Process exited after 39.54 seconds with return value 0
请按任意键继续. . .



*/ 
