/* Date��2020/3/19
 * 7-5����д��4���еĺ�׺������������scanf������(��)sscanf����ʵ�������Լ�����ת��
 */ 
#include <stdio.h>
#include <ctype.h>

#define NUMBER '0'
#define MAXVAL 100 
#define BUFSIZE 100
#define abs(x) (x > 0 ? (x) : (-x))

void ungetch(int c);
int getch(void);
int getop();
double pop(void);
void push(double x);
double atof(char s[]);


/* ջ */ 
double val[MAXVAL];
int sp = 0;

/* ����ungetch�Ļ����� */ 
char buf[BUFSIZE];
int bufp = 0;

//char s[100];
double oper;
int err = 0;	/* ���������� */ 

void main(void)
{
	char c;
	double op2;
	
	int j;
	while ((c = getop()) != EOF)
	{
		switch(c)
		{
			case NUMBER:
				push(oper);
				break;
			case '+'   :
				push(pop() + pop());
				break;
			case '*'   :
				push(pop() * pop());
				break;
			case '-'   :
				op2 = pop();
				push(pop() - op2);
				break;
			case '/'   :
				op2 = pop();
				if (op2 != 0) 
					push(pop() / op2);
				else
				{
					err = 1; 
					printf("error: zero divisor\n");
				}
				break;
			case '%':
				op2 = pop();
				if (op2 != 0) 
					push((int)pop() % (int)op2);
				else
				{
					err = 1; 
					printf("error: zero divisor\n");
				}
				break;				
			case '\n'   :
				if (!err)
				{
					printf("result = %.8g\n", pop());
					err = 0;
				}
				break;
			default	   :
				err = 1;
				printf("error: unknown commandn");
				break;
		}
#if 0
		printf("c = %c, sp = %d, val[]= ", c, sp);
		for (j = 0; j < 5; j++)
			printf("%g ", val[j]);
		putchar('\n');
#endif
	}
	
	return;
}

void push(double x)
{
	if (sp < MAXVAL) 
		val[sp++] = x;
	else
		printf("error: stack full, can't push %g\n", x);
}

double pop(void)
{
	if (sp > 0)
		return val[--sp];
	else
	{
		printf("error: stack empty\n");
		return 0.0;
	}
}

int getop()
{
	int i, c;
	
	/* �����հ� */ 
	while ((c = getch()) == ' ' || c == '\t')	
		;
	
	//putchar(c);
	/* ������ */ 
	if (!isdigit(c)){
		//putchar(c);
		return c;
	}
	else
	{
		ungetc(c, stdin);		// �⺯�� 
		scanf("%lf", &oper);		
	}
	//printf("oper = %lf\n", oper);
		
	return NUMBER;
}

int getch(void)
{
	return (bufp > 0 ? buf[--bufp] : getchar());
}

void ungetch(int c)
{
	if (bufp >= BUFSIZE)
		printf("ungetch: too many characters\n");
	else
		buf[bufp++] = c;
}



double atof(char s[])
{
	double base, pow;
	int i, sign, exp;
	
	/* ·���հ� */ 
	for (i = 0; isspace(s[i]); i++)
		;
		
	sign = (s[i] == '-') ? -1 : 1;
	if (s[i] == '+' || s[i] == '-')
		i++;
	
	for (base = 0.0; isdigit(s[i]); i++)
	{
		base = 10.0 * base + (s[i] - '0');
		//printf("sign = %d, base = %g\n", sign, base);
	}	
	
	if (s[i] == '.')
		i++;
	
	for (pow = 1.0; isdigit(s[i]); i++)
	{
		base = 10.0 * base + (s[i] - '0');
		pow *= 10.0;
		//printf("base = %g\n", base);
	}
	base = sign * base / pow;		/* ���� */ 

#if 1	
	/* ָ�� */ 
	if (s[i] == 'e' || s[i] == 'E')
	{
		sign = (s[++i] == '-' ? -1 : 1);
		if (s[i] == '-' || s[i] == '+')
			i++;
		
		for (exp = 0; isdigit(s[i]); i++)
			exp = 10 * exp + (s[i] - '0');
		
		if (sign == -1)
			while (exp-- > 0)
				base /= 10;
		else
			while (exp-- > 0)
				base *= 10;
	}
#endif	
	return base;
}


