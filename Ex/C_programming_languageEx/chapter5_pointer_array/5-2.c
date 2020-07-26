/* Date：2020/3/7 
 * 5-2：模仿函数getint的实现方法，编写一个读取浮点数的函数getfloat。getfloat函数的返回值应该是什么类型？
 *
 *		可以处理+123, -123, -12.34, .213, 0.213, +, -
 *
 *		在 getfloat中，只要从输入流中得到的不是digit, +, -, ., EOF 
 *		一概压回buf[]中 
 */ 
 
#include <stdio.h>
#include <ctype.h> 
#define MAX 100

int getfloat(float *pn);
char getch(void);
void ungetch(char c);


int main(void)
{
	float a[MAX] = {0};
	int i; 
	
	for(i = 0; i < MAX && getfloat(&a[i]) != EOF; i++)
		;
		
	/* 打印前20个数 */ 
	for (i = 0; i < 20; i++)
		printf("a[%d] = %.5g\n", i, a[i]);
	
	return 0;
}

int getfloat(float *pn)
{
	int c, sign;
	float pow;
	
	/* 跳过空白 */ 
	while (isspace(c = getch()))
		;
	
	/* 不是数字 */	
	if (!isdigit(c) && c != EOF && c != '+' && c != '-' && c != '.')
	{
		ungetch(c);
		return 0;
	}
	
	/* 处理符号 */ 
	sign = (c == '-' ? -1 : 1);
	if (c == '+' || c == '-')
	{
		c = getch();
		if (!isdigit(c))
		{
			ungetch(c);
			*pn = 0;
			return c;
		}
	}
	
	/* 处理数字 */ 
	for (*pn = 0; isdigit(c); c = getch())
		*pn = 10 * *pn + (c - '0');
		
	/* 处理小数 */ 
	if (c == '.') 
	{
		if (isdigit(c = getch()))
			for (pow = 1.0; isdigit(c); c = getch())
			{
				*pn = 10 * *pn + (c - '0');
				pow *= 10.0;
			}
		else
		{
			ungetch(c);
			ungetch('.');
			return '.';
		}
	}
	
	*pn *= sign / pow;
	
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
        -23.6
123.5
        +12.3
+
 -
123.
a[0] = -23.6
a[1] = 123.5
a[2] = 12.3
a[3] = 0
a[4] = 0
a[5] = 123
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
Process exited after 33.1 seconds with return value 0
请按任意键继续. . .

*/ 
