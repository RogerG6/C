/* Date��2020/2/17
 * 4-10����һ�ַ�����ͨ��getline�����������������У���������¿��Բ�ʹ��getch��ungetch��������������һ�����޸ļ��������� 
 */ 

#include <stdio.h>
#include <ctype.h>
#include <math.h>

#define NUMBER '0'
#define MAXVAL 100 
#define BUFSIZE 100
#define abs(x) (x > 0 ? (x) : (-x))

void ungetch(int c);
int getch(void);
int getop(char s[]);
double pop(void);
void push(double x);
double myatof(char s[]);
void clear(void);
int getline(char s[], int lim);


/* ջ */ 
double val[MAXVAL];
int sp = 0;

/* ����ungetch�Ļ����� */ 
char buf[BUFSIZE];
int bufp = 0;

char s[100];	/* ������� */ 
int err = 0;	/* ���������� */ 

/* ��Ŵӱ�׼����õ����ַ��� */ 
char line[MAXVAL];
int li = 0; 

void main(void)
{
	char c, var;
	double op1, op2;
	double variable[26];	/* ��ű��� */ 
	double v;
	
	int j;
	printf("?����ӡջ��Ԫ�أ�������ջ��Ԫ��\n");
	printf("d������ջ��Ԫ��                \n");
	printf("t������ջ��Ԫ��                \n");
	printf("c: ���ջ                      \n");
	printf("s��sin����                     \n");
	printf("e: eָ��                       \n");
	printf("p: powָ��(op1Ϊ������op2Ϊָ��)\n");
	
	
	while ((c = getop(s)) != EOF)
	//int cnt = 10;
	//while (cnt-- > 0)
	{
		switch(c)
		{
			case NUMBER:
				push(myatof(s));
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
			case '=':
				pop();
				if (var >= 'A' && var <= 'Z')
					variable[var - 'A'] = pop();
				else
					printf("error: no variable name\n");
				err = 1;
				break;
			case '?':	/* ��ӡջ��Ԫ�� */ 
				op2 = pop();
				printf("stack top: %.8g\n", op2);
				push(op2);
				break;
			case 'c':	/* ���ջ */ 
				clear();
				break;
			case 'd':	/* ����ջ��Ԫ�� */ 
				op2 = pop();
				push(op2);
				push(op2);
				break;
			case 't':	/* ����ջ��Ԫ�� */ 
				op1 = pop();
				op2 = pop();
				push(op1);
				push(op2);
				break;
			case 's':
				push(sin(pop()));
				break;
			case 'e':
				push(exp(pop()));
				break;
			case 'p':
				op2 = pop();
				op1 = pop();
				if ((op1 == 0 && op2 <= 0) || (op1 < 0 && op2 - (int)op2 != 0))
					err = 1;
				else
					push(pow(op1, op2));
				break;
			case '\n'   :
				if (!err)
				{
					v = pop();
					printf("result = %.8g\n", v);
				}
				else
					err = 0;
				break;
			default	   :
				if (c >= 'A' && c <= 'Z') 
					push(variable[c - 'A']);
				else if (c == 'v')
					push(v);
				else
				{
					err = 1;
					printf("error: unknown command %s\n", s);
				}
				break;
		}
		var = c;
#if 0	
		printf("s = %s, c = %c, sp = %d, val[]= ", s, c, sp);
		for (j = 0; j < 5; j++)
			printf("%g ", val[j]);
		putchar('\n');
#endif
	}
	
	return;
}

void clear(void)
{
	sp = 0;
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

int getline(char s[], int lim) 
{
	int c, i, j;
	
	j = 0;
	for (i = 0; (c = getchar()) != EOF && c != '\n'; i++)
		if (i < lim - 2)
		{
			s[j] = c;
			j++;
		}
	
	if (c == '\n')
	{
		s[j] = c;
		i++;
		j++;
	}
	s[j] = '\0';
	return i;
}

int getop(char s[])
{
	/* jָ��s[] */ 
	int j = 0, c;

	if (line[li] == '\0') 
		if (getline(line, MAXVAL) == 0)
			return EOF;
		else
			li = 0;
	
	/* �����հ� */ 
	while ((c = line[li++]) == ' ' || c == '\t')	
		;

	/* ������ */ 
	if (!isdigit(c) && c != '.' && c != '-')
		return c;

#if 1		
	/* ���� */ 
	if (c == '-') 
	{		
		if (isdigit(c = line[li++]) || c == '.')
			s[j++] = '-';
		else
		{
			li--;
			return '-';
		}
	}
#endif	
	
	/* ���� */
	if (isdigit(c))
		do
			s[j++] = c;
		while (isdigit(c = line[li++]));
	
			
	/* С�� */ 
	if (c == '.')
		do
			s[j++] = c;
		while (isdigit(c = line[li++]));
	
	li--;
	
	s[j] = '\0';
	
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



double myatof(char s[])
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


