# include <stdio.h>
int count(int n);

int main(void)
{
	int num;
	
	puts("Enter a number to count how many open bits.");
	while (scanf("%d", &num) != 1)
		puts("Please enter a integar.");
	printf("There are %d open bits in %d\n", count(num), num);
	
	return 0;
}

int count(int n)
{
	int ct = 0;
	
	for (int i = 0; i < 8 * sizeof(int); i++)
	{
		if (n & 01 == 1)
			ct++;
		n >>= 1;
	}
	return ct;
}
