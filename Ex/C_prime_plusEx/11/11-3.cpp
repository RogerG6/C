# include <stdio.h>
# include <ctype.h>
void read_word(char st[]);

int main (void)
{
	char s[81];
	
	read_word(s);
	
	puts(s);
	
	return 0;
}
void read_word(char st[])
{
	int c;
	while (! isalpha(c = getchar()))
		continue;
	do
	{
		*st++ = c;
		
	} while ((c = getchar())  && isalpha(c));
	*st = '\0';
		while (c != '\n')
			c = getchar();
}
