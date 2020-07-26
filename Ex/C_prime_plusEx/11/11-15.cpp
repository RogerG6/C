# include <stdio.h >
# include <ctype.h>
int atonum(char * st);  //���ַ���ת������ֵ��������������С���� 
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
int atonum(char * st)   //�������ַ���ת���������� 
{
	int tot = 0;
	
	while (*st != '\0')
	{
		while (isspace(*st))
			st++;
		if (isdigit(*st))  //�ж��׸��ǿ��ַ��Ƿ�Ϊ�����ַ� 
		{
			while (isdigit(*st) && *st != '\0')
			{
				tot = 10 * tot + (*st - 48);
				st++;
			}
			return tot;
		}
		else if (*st == '-')   //�ж��׸��ǿ��ַ��Ƿ�Ϊ- 
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
