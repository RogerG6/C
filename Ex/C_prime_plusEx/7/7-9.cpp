# include <stdio.h>
# include <math.h>
int main(void)
{
/*	int n, i, j, k;
	
	do
	{
		printf("Enter a positive integer: ");
		scanf("%d", &n);
	}while (n <= 0);
	printf("\nAll primer numbers(<=%d): \n", n);
	
	for (i = 2, k = 0; i <= n; i++, k = 0)
	{
		for (j = 2; j < i; j++)
			if (i % j == 0)
				k++;
		if (0 == k)
			printf("%d ", i);
	}
	return 0;*/
	int input = 0;

    printf("please input the upper number:");
    scanf("%d", &input);

    int i = 0;
    int j = 0;

    for (i = 2; i <= input; i++)
    {
        for (j = 2; j < sqrt((double)i); j++)   //该少算法循环次数 
        {
            if (i % j == 0)
            {
                break;
            }
        }
        if (j > sqrt(i))
        {
            printf("%d ", i);
        }
    }
}
