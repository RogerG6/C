# include <stdio.h> 

int Fibonacci(int n);

int main(void)
{
	int n, i;
	printf("������Fibonacci������");
	while(scanf("%d", &n) == 1)
	{
		for (i = 1; i <= n; i++)
		{
			printf("%d ", Fibonacci(i));
			if (i % 10 == 0)
				putchar('\n');
		}
		//printf("Fibonacci���е�%d��Ϊ��%d\n", n, Fibonacci(n));
	}
	
	return 0;
}

int Fibonacci(int n)
{
	int i;
	int f1, f2, f3;
	f1 = f2 = f3 = 1;
	for (i = 3; i <= n; i++)
	{
		f3 = f1 + f2;
		f1 = f2;
		f2 = f3;
	}

	return f3;
}
