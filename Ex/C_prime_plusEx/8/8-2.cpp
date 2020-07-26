# include <stdio.h>
int main(void)
{
	int ch;
	int i = 0;
	
	while ((ch = getchar()) != EOF)
	{
		i++;
		if (ch < 32)
		{
			if(ch == 9 )
				printf("\\t ");
			else if (ch == 10)
			{
				printf("\\n");
				i = 0;
			}	
			else
			 printf("^%c ", ch + 64);
		}
		else
			printf("%c-%d ", ch, ch);
		
		
		
	//	printf("%d", i);
		if (i % 10 == 0)
			printf("\n");
	}
	
	return 0;
}
