//2018年10月11日 20时22分 
//将天数转换成周数和天数
# include <stdio.h> 
int main(void) 
{
	int days, weeks, left;
	
	printf("Please enter days:");
	scanf("%d", &days);
	
	while (days > 0)
	{
		weeks = days / 7;
		left = days % 7;
		printf("%d days is %d weeks and %d days\n", days, weeks, left);
		
		printf("Please enter days:");
		scanf("%d", &days);
	}
	
	return 0;
}
