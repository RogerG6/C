# include <stdio.h>

void larger_of1(double *, double *);
double larger_of2(double, double);

int main(void)
{
	double a, b;
	a = 3.4;
	b = 7.8;
	printf("a = %lf, b = %lf\n", larger_of2(a, b), larger_of2(a, b));  //返回值法 
	larger_of1(&a, &b);
	printf("a = %lf, b = %lf\n", a, b);  //指针法 
	
	return 0;
}

//用指针
void larger_of1(double * i, double * j) 
{
	*i > *j ? *j = *i : *i = *j;
}

//用返回值
double larger_of2(double i, double j) 
{
	return i > j ? i : j;
}
