# include <stdio.h> 

void sort(double *, double *, double*);

int main(void)
{
	double i, j, k;
	
	printf("Enter three numbers:");
	scanf("%lf%lf%lf", &i, &j, &k);
	sort(&i, &j, &k);
	printf("i = %lf, j = %lf, k = %lf\n", i, j, k);
	
	
	return 0;
}

void sort(double * a, double * b, double * c)
{
	double temp;
	if (*a > *b)
	{
		temp = *a;
		*a = *b;
		*b = temp;	
	}
	if (*b > *c)	
	{
		temp = *b;
		*b = *c;
		*c = temp;
	}
	if (*a > *b)
	{
		temp = *a;
		*a = *b;
		*b = temp;	
	}
}
