# include <stdio.h>
# define N 4
char * s_gets(char * st, int n);

int main(void)
{
	char tr[N];
	
//	printf("%p, %p\n", tr, s_gets(tr, N));
	s_gets(tr, N);
	puts(tr);
	
	return 0;
}

char * s_gets(char * st, int n)
{
	char * ret_val;
	
	ret_val = fgets(st, n, stdin);
	if (ret_val)
	{
			while (*st != '\n' && *st != '\0' && *st != '\t')
				st++;
			if (st == ret_val + n - 1) 	 //µ±¶Áµ½×Ö·û´®Ä©Î²Ê± 
			{
		//		printf("a\n")	;
				while (getchar() != '\n')
						continue;
			}
			*st = '\0';			
	}

	return ret_val;
}
