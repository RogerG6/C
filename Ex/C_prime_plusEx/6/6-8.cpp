# include <stdio.h>
int main(void)
{
	float i, j;
	int k;
	
	printf("Please enter two numbers:")	;
	
	while ((scanf("%f%f", &i, &j)) == 2)
	{
		printf("(%0.2f - %0.2f) / (%0.2f * %0.2f) = %0.2f\n", i, j, i, j, (i - j)/(i * j));
		printf("Please enter two numbers:")	;
		scanf("%f%f", &i, &j);
	}
	
	return 0;
}
