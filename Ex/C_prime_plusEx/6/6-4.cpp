# include <stdio.h>
int main(void)
{
	int i, j;
	char ch = 'A';
	for (i = 1; i < 7; i++)
	{
		for (j = 1; j <= i; j++)
			printf("%c", ch++);
		printf("\n");
	}
	
	return 0;
}
