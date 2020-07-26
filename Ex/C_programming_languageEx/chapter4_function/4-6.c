/* Date：2020/2/16
 * 4-6: 给计算器程序增加处理变量的命令(提供26个具有单个英文字母变量名的变量很容易) 
 *		增加一个变量存放最近打印的值 
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


/* 栈 */ 
double val[MAXVAL];
int sp = 0;

/* 用于ungetch的缓冲区 */ 
char buf[BUFSIZE];
int bufp = 0;

char s[100];
int err = 0;	/* 检测除法错误 */ 

void main(void)
{
	char c, var;
	double op1, op2;
	double variable[26];	/* 存放变量 */ 
	double v;
	
	int j;
	printf("?：打印栈顶元素，不弹出栈顶元素\n");
	printf("d：复制栈顶元素                \n");
	printf("t：交换栈顶元素                \n");
	printf("c: 清空栈                      \n");
	printf("s：sin函数                     \n");
	printf("e: e指数                       \n");
	printf("p: pow指数(op1为底数，op2为指数)\n");
	
	while ((c = getop(s)) != EOF)
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
			case '?':	/* 打印栈顶元素 */ 
				op2 = pop();
				printf("stack top: %.8g\n", op2);
				push(op2);
				break;
			case 'c':	/* 清空栈 */ 
				clear();
				break;
			case 'd':	/* 复制栈顶元素 */ 
				op2 = pop();
				push(op2);
				push(op2);
				break;
			case 't':	/* 交换栈顶元素 */ 
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
	
	/* 路过空白 */ 
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
	base = sign * base / pow;		/* 底数 */ 

#if 1	
	/* 指数 */ 
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


