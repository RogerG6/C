# include <stdio.h>

double pow(int, int);

int main(void)
{
	int i, j;
	while(scanf("%d%d", &i, &j) == 2)
		printf("%lf\n", pow(i, j));
	
	return 0;
}

double pow(int a, int n)
{
	double pow = 1;
	int i;
	
	if (n < 0)
	{
		for (i = 1; i <= -n; i++)
		{
			if (0 ==a)
				return 0;
			pow *= 1.0/a;
		}
	}
	else
		for (i = 1; i <= n; i++)
			pow *= a;
		
	
	return pow;
	
}
