# include <stdio.h>
# include <math.h>
void show_ar(double * ar, int n);
void transform(double * source, double * target, int n, double (* pf)(double));
double add_1(double dou);
double multi_2(double dou);

int main(void)
{
	int i;
	double source[100];
	double target[100];
	for (i = 0; i < 100; i++)  //初始化源数组 
		source[i] = -50 + i;
	puts("Here is source array:");
	show_ar(source, 100);
	//function 1: abs
	transform(source, target, 100, fabs);
	puts("Here is function 1 target array:");
	show_ar(target, 100);
	//function 2: ceil(返回大于或等于参数的最小整数值)
	transform(source, target, 100, ceil);
	puts("Here is function 2 target array:");
	show_ar(target, 100);
	//function 3: 源数组元素+1 
	transform(source, target, 100, add_1);
	puts("Here is function 3 target array:");
	show_ar(target, 100);
	//function 4：源数组元素*2 
	transform(source, target, 100, multi_2);
	puts("Here is function 4 target array:");
	show_ar(target, 100);
	
	return 0;
}

void transform(double * source, double * target, int n, double (* pf)(double))
{
	for (int i = 0; i < n; i++)
		target[i] = (*pf)(source[i]);
}

void show_ar(double * ar, int n)
{
	for(int i = 0; i < n; i++)
	{
		if (i != 0 && i % 10 == 0)
			putchar('\n');
		printf("%-7.2lf ", ar[i]);
		
	}
	putchar('\n');
	putchar('\n');
}

double add_1(double dou)
{
	return dou + 1;
}

double multi_2(double dou)
{
	return dou * 2;
}
