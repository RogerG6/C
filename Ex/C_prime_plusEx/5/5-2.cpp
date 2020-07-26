# include <stdio.h> 
int main(void)
{
	int num, i;
	
	printf("Please enter a number:");
	scanf("%d", &num);
	i = num;
	while(num <= i+10)
		printf("%d ", num++);
	printf("\n");
	
	return 0;
}
