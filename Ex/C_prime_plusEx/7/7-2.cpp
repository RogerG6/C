# include<stdio.h>
int main(void)
{
	int n_chars = 0;
	char c;
	
	while((c = getchar()) != '#')
	{
		n_chars++;
		printf("%c-%3d    ", c, c);
		if (n_chars % 8 == 0)
			putchar('\n');
	}
	
	return 0;
}
