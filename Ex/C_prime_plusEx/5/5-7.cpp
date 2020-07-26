# include <stdio.h>

double lfang(double);
int main(void)
{
	double n;
	
	printf("Enter a number:");
	scanf("%lf", &n);
	
	printf("%lf\n", lfang(n));
	
	return 0;
}

double lfang(double i)
{
	double rlt;
	rlt = i*i*i;
	
	return rlt;
}
