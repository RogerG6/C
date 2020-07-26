/* Date��2020/3/7 
 * 5-2��ģ�º���getint��ʵ�ַ�������дһ����ȡ�������ĺ���getfloat��getfloat�����ķ���ֵӦ����ʲô���ͣ�
 *
 *		���Դ���+123, -123, -12.34, .213, 0.213, +, -
 *
 *		�� getfloat�У�ֻҪ���������еõ��Ĳ���digit, +, -, ., EOF 
 *		һ��ѹ��buf[]�� 
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
		
	/* ��ӡǰ20���� */ 
	for (i = 0; i < 20; i++)
		printf("a[%d] = %.5g\n", i, a[i]);
	
	return 0;
}

int getfloat(float *pn)
{
	int c, sign;
	float pow;
	
	/* �����հ� */ 
	while (isspace(c = getch()))
		;
	
	/* �������� */	
	if (!isdigit(c) && c != EOF && c != '+' && c != '-' && c != '.')
	{
		ungetch(c);
		return 0;
	}
	
	/* ������� */ 
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
	
	/* �������� */ 
	for (*pn = 0; isdigit(c); c = getch())
		*pn = 10 * *pn + (c - '0');
		
	/* ����С�� */ 
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
�밴���������. . .

*/ 
