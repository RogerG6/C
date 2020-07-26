# include <stdio.h>

float cal(float, float);
int main(void)
{
	float i, j;
	printf("Please enter two numbers:")	;
	while((scanf("%f%f", &i, &j)) == 2)
	{
		printf("(%0.2f - %0.2f) / (%0.2f * %0.2f) = %0.2f\n", i, j, i, j, cal(i,j));
		printf("Please enter two numbers:")	;
	}	
	
	return 0;
}

float cal(float i, float j)
{
	float k;
	k = (i - j)/(i * j);
	
	return k;
}
