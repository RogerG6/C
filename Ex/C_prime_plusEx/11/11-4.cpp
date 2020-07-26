# include <stdio.h> 
# include <ctype.h>
void read_word(char * st, int n);

int main(void)
{
	char word[5];
	read_word(word, 5);
	puts(word);
//	putchar(getchar());
	return 0;
}

void read_word(char * st, int n)
{
	int c, ct = 1;
	
	while (! isalpha(c = getchar()))
		continue;
//	printf("%d\n", ct);
	while (ct < n && isalpha(c))
	{
		*st = c;
		ct++;
		st++;
		c = getchar();
	}
	*st = '\0';   //²»ÄÜÊ¡ 
	if (ct == n)
		while (getchar() != '\n')
			continue;
}
