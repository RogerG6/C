# include <stdio.h> 
# include <time.h>
double tim(double n);

int main(void)
{
	double t;
	
	while (scanf("%lf", &t) != 1)
		continue;
	printf("时间差为：%lf, 循环运行时间为：%lf\n", t, tim(t));
	
	return 0;
}

double tim(double n)
{
	double t = (double)(n / CLOCKS_PER_SEC);
	clock_t t1, t2;
	
	
	for(int i = 0,t1 = clock(); i < 10; i++)
	{
		for (int j = 0; j <= i; j++)
			printf("$");
		putchar('\n');
	}
	t2 = clock();
	
	return (double)((t2-t1) / CLOCKS_PER_SEC);
}
