# include <stdio.h>
# include <ctype.h>   //用户无论输入大写还是小写，都能正确识别 
# include <string.h>

# define ANSWER "Grant"
# define SIZE 40
char * s_gets(char * st, int n);
void to_right(char * st);

int main(void)
{
	char tr[SIZE];
	
	puts("Who is buried in Grant's tomb?");
	s_gets(tr, SIZE);
	to_right(tr);
	while (strcmp(tr, ANSWER) != 0)
	{
		puts("No, that's wrong. Try again.");
		s_gets(tr, SIZE);
		to_right(tr);
	}
	puts("That's right!");
	
	return 0;
}

char * s_gets(char * st, int n)
	{
		char * ret_val;
		char * p;
		
		ret_val = fgets(st, n, stdin);
		if(ret_val)
		{
			p = strchr(st, '\n');
			if (p)
				*p = '\0';
			else
				while ( getchar() != '\n')
					continue;
		}
		return ret_val;
	}
	
void to_right(char * st)
{
	if (*st)
		*st = toupper(*st);
	while(*++st)
		*st = tolower(*st);
}
