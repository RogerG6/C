/* Date：2020/2/15
 * 4-2: 对atof函数进行扩充，使它可以处理形如：
 *		123.45e-6
 *		的科学表示法，其中，浮点数后面会紧跟一个e或E以及一个指数(可能有正负号) 
 */ 
 
#include <stdio.h>
#include <ctype.h>

int abs(int x)
{
	return x > 0 ? x : -x;
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

void main(void)
{
	char s[100];
	
	printf("Enter a string(eg. 123.45e-6):");
	gets(s);
	
	printf("%s(string) = %g(double)\n", s, atof(s));
	
	return;
}

/*
Enter a string(eg. 123.45e-6):123.45e-6
123.45e-6(string) = 0.00012345(double)

--------------------------------
Process exited after 6.434 seconds with return value 39
请按任意键继续. . .
*/ 
