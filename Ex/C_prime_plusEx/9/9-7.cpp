# include <stdio.h>
# include <ctype.h>

int alpha(char);

int main(void)
{
	char ch;
	while ((ch = getchar()) != EOF)
		printf("%d  ", alpha(ch));
	
	return 0;
}

int alpha(char c)
{
	int pl = -1;
	if(isalpha(c))
	{
		if (c >= 'A' && c <= 'Z')
			pl = c - 64;
		if (c >= 'a' && c <= 'z')
			pl = c - 96;
	}
	return pl;
}
