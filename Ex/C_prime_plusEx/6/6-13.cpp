# include <stdio.h> 
int main(void)
{
	int ch[8];
	int i, j;
	
	for(i = 0, j = 1; i < 8; i++)
		printf("ch[%d] = %d\n", i, j = 2*j);
		
	i = 0;
	j = 1;
	do
	{
		printf("ch[%d] = %d\n", i, j = 2*j);
	}while(++i < 8);
	
	return 0;
}
