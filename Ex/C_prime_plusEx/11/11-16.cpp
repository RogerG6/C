# include <stdio.h> 
# include <ctype.h>
void toupper_s(char * st);
void tolower_s(char * st);
void s_gets(char * st, int n);

int main(int argc, char * argv[])
{
	char str[81];
//	int c;
	
	s_gets(str, 81);
//	c = strcmp(argv[1], "-p");
	if ('p' == argv[1][1] && '-' == argv[1][0])
		puts(str);
	if ('u' == argv[1][1] && '-' == argv[1][0])
	{
		toupper_s(str);
//		puts(str);
	}
	if ('l' == argv[1][1] && '-' == argv[1][0])
	{
		tolower_s(str);
//		puts(str);
	}
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

void toupper_s(char * st)
{
	while(*st != '\0')
	{
		if (isalpha(*st))
			putchar(toupper(*st));;
		st++;
	}
}

void tolower_s(char * st)
{
	while(*st != '\0')
	{
		if (isalpha(*st))
			putchar(tolower(*st));;
		st++;
	}
}
