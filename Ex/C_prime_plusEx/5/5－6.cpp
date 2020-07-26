# include <stdio.h>
int main(void) 
{
	int days;
	int money, i;
	
	printf("Enter days:");
	scanf("%d", &days);
	
	i = money = 0;
	while(i++ < days)
		money = money + i*i;
	printf("You can earn $ %d in %d days!\n", money, days);
	
	return 0;
} 
