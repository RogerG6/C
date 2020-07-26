# include <stdio.h>
int main(void)
{
	const float i = 0.1;
	const float j = 0.05;
	float sum1 = 100;
	float sum2 = 100;
	int year = 0;
	
	do
	{
		sum1 += 100 * i;
		sum2 *= 1+j;
		year++;
	}while(sum1 > sum2);
	
	printf("After %d years, Deirdre will exceed Daphne!\n", year);
	printf("Daphne:$ %f\nDeirdre:$ %f\n", sum1, sum2);
	
	return 0;
}
