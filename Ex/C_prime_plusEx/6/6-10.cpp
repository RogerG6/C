# include <stdio.h>
int main(void)
{
	int low, up, sum, i;
	
	printf("Enter lower and upper integer limits:");
	scanf("%d%d", &low, &up);
	i = low;
	while(i <= up )
	{
		for (i , sum = 0; i <= up; i++)
			sum += i * i;
		printf("The sums of the squares from %d to %d is %d\n", low, up, sum);
		
		printf("Enter lower and upper integer limits:");
		scanf("%d%d", &low, &up);
		i =low;
	}
	printf("Done\n");
	
	return 0;
}
