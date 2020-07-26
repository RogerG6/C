# include <stdio.h>
int main(void)
{
	int a[8];
	int i;
	
	printf("Enter 8 numbers:");
	for(i = 0; i < 8; i++)
	{
		scanf("%d", &a[i]);
	}
	for (i = 0; i<8; i++)
		printf("%d ", a[7-i]);  
}
