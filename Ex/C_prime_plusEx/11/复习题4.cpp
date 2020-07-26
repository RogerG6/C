# include <stdio.h>
# include <string.h>
char * s_gets(char * st, int n);
int strlen(char * p);
char * spa(char * str);

int main(void)
{
	char g[40] ;
//	char s[5] = "cd";
	
//	strcat(s, g);
	s_gets(g, 40);
	puts(g);
	printf("g×Ö·û´®ÓĞ%d¸ö×Ö·û\n", strlen(g));
	
	return 0;
}

char * s_gets(char * st, int n)
	{
		char * ret_val;
		
		ret_val = fgets(st, n, stdin);
		if (ret_val)
		{
			while (*st != '\0' && *st != '\n')
				st++;
			if (*st == '\n')	
				*st = '\0';
			else
				while (getchar() != '\n')
					continue;
		}
		return ret_val;
	}
	
	int strlen(char * p)
	{
		int count = 0;
		
		while (*p++)
		{
			count++;
		}
		return count;
	}
	
	 char * spa(char * str)
	{
		while (*str)
		{
			if (*str == ' ')
				return str;
			str++; 
		}
		return NULL;	
	}

