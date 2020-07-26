# include <stdio.h>

void Temperatures(double);
int main(void)
{
	double fahr;
	int i;
	printf("Please enter a fahr temperature:");
	i = scanf("%lf", &fahr);
//	printf("%d", i);
	while (i != 0 )
	{
		Temperatures(fahr);
		printf("Please enter a fahr temperature:");
		i = scanf("%lf", &fahr);
	}	
	return 0;
}

void Temperatures(double t)
{
	const float K = 273.16;
	double ces,klv;
	
	ces = 5.0 / 9.0 * (t - 32.0) ;
	klv = t + K;\
	
	printf("Fahr = %0.2lf\n", t);
	printf("Celsuis = %0.2f\n", ces);
	printf("Kelvin = %0.2f\n", klv);
	
}
