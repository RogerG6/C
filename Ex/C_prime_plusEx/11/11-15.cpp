# include <stdio.h >
# include <ctype.h>
int atonum(char * st);  //把字符串转换成数值（正数，负数，小数） 
void s_gets(char * st, int n);

int main(void)
{
	char str[81];
	
	s_gets(str, 81);
	printf("%d\n", atonum(str));
	
	return 0;
}

void s_gets(char * st, int n)
{
	fgets(st, n, stdin);
	while (*st != '\n' && *st != '\0')
		st++;
	if (*st == '\n')
		*st = '\0';
	else
		while (getchar() != '\n')
			continue;
}
int atonum(char * st)   //将数字字符串转换成整型数 
{
	int tot = 0;
	
	while (*st != '\0')
	{
		while (isspace(*st))
			st++;
		if (isdigit(*st))  //判断首个非空字符是否为数字字符 
		{
			while (isdigit(*st) && *st != '\0')
			{
				tot = 10 * tot + (*st - 48);
				st++;
			}
			return tot;
		}
		else if (*st == '-')   //判断首个非空字符是否为- 
		{
			if (isdigit(*++st))
			{
				while (isdigit(*st) && *st != '\0')
				{
					tot = 10 * tot + (*st - 48);
					st++;
				}
				return -tot;
			}
			else 
				return 0;
		}
		else 
		 	return 0;
	}
	
}
