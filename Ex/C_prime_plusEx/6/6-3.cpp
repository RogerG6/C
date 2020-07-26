# include <stdio.h>
int main (void)
{
	/*int i;
	char ch;
	
	for(i = 5; i >= 0; i--)
	{
		for(ch = 'F'; ch >= 'A'+i; ch--)
			printf("%c", ch);
		printf("\n");
	}   */
	
	int i, j;
	char ch[27] = "ABCDEFG";
	
	for (i = 5; i >= 0; i--)
	{
		for (j = 5; j >= i; j--)
			printf("%c", ch[j])	;
		printf("\n");
	}
	
	return 0;
}
