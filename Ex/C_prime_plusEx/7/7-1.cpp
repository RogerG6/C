# include <stdio.h>
int main(void)
{
	int n_space = 0, n_return = 0, n_else = 0;
	int c;
	
	while ((c = getchar()) != '#')
	{
		if (' ' == c)
			n_space++;
		else if ('\n' == c)
			n_return++;
		else
			n_else++;
	}
	printf("n_space = %d, n_return = %d, n_else = %d\n", n_space, n_return, n_else);
	
	return 0;
}
