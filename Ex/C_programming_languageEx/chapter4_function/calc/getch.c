#include <stdio.h>
#include <ctype.h>

#define BUFSIZE 100

/* 用于ungetch的缓冲区 */ 
char buf[BUFSIZE];
int bufp = 0;

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

