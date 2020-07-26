/* Date：2020/3/10 
 * 5-10：编写程序expr, 以计算从命令行输入的逆波兰表达式的值，其中每个运算符或操作数用一个单独的参数表示。例如：
 *	     expr 2 3 4 + *，将计算2*(3+4)
 */ 
#include <stdio.h>
#include <ctype.h>

double atof(char s[]);

int main(int argc, char *argv[])
{
	int c;
	double op1, op2;
	double stack[100];
	int sp = 0;
	
	if (argc < 1)
	{
		printf("Usage: expr 2 3 4 + *\n");
		return -1;
	}
	
	while (--argc > 0)
	{
		if ((c = (*++argv)[0]) == '-' && isdigit((*argv)[1]))
		{
			stack[sp++] = -1 * atof(*argv + 1);
			//printf("%g ", stack[sp-1]);
			continue;
			//c = NUMBER;
		}
		else if (isdigit(c))
		{
			stack[sp++] = atof(*argv);
			//printf("%g ", stack[sp-1]);
			continue;
		}
		
		switch (c)
		{
			case '+':
				op1 = stack[--sp];
				op2 = stack[--sp];
				stack[sp++] = op1 + op2;
				break;
			case '*':
				op1 = stack[--sp];
				op2 = stack[--sp];
				stack[sp++] = op1 * op2;				
				break;
			case '-':
				op1 = stack[--sp];
				op2 = stack[--sp];
				stack[sp++] = op2 - op1;
				break;
			case '/':
				op1 = stack[--sp];
				if (op1 == 0)
				{
					printf("error: zero division\n");
					return -1;
				}
				op2 = stack[--sp];
				stack[sp++] = op2 / op1;				
				break;
			default:
				printf("Unillegal opertor %c\n", c);
				return -1;
		}
			
	}
	printf("Result: %.8g\n", stack[--sp]);
	
	return 0;
}

double atof(char s[])
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

