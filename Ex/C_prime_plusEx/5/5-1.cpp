//2018年10月11日 20时11分 
//将分钟转换成小时和分钟表示  
# include <stdio.h>
int main (void)
{
	const int M_PER_H = 60;
	int min, hour, left;
	
	printf("Please enter your minutes: ");
	scanf("%d", &min);
	while(min > 0)
	{
		hour = min / M_PER_H;
		left = min % M_PER_H;
		printf("%d minutes is %d hours %d minutes!\n", min, hour, left);
		
		printf("Please enter your minutes: ");
		scanf("%d", &min);
	}
	
	return 0;
}
