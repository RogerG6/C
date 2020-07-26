# include <stdio.h>
int main(void)
{
	int i, j, n;
	float sum1, sum2;
	
	printf("Enter a final number:");
	scanf("%d", &n);
	
	while(n > 0)
	{
		for (i = 1, sum1 = 0; i < n+1; i++)
			sum1 += 1.0/i;
		printf("sum1 = %f\n", sum1);
		
		for (i =1, j = 1, sum2 = 0; i <= n; i++, j = (-1)*j)  //用状态变量 j 来迭代 
		{	
			sum2 += (1.0/i)*j;
		}	
		printf("sum2 = %f\n", sum2);
		
		printf("Enter a final number:");
		scanf("%d", &n);
	}
	
	return 0;
}

/*在Dev－C++5.10中运行结果为：
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Enter a final number:10
sum1 = 2.928968
sum2 = 0.645635
Enter a final number:100
sum1 = 5.187378
sum2 = 0.688172
Enter a final number:1000
sum1 = 7.485478
sum2 = 0.692646
Enter a final number:10000
sum1 = 9.787613
sum2 = 0.693091
Enter a final number:100000
sum1 = 12.090851
sum2 = 0.693134
Enter a final number:1000000
sum1 = 14.357358
sum2 = 0.693137
Enter a final number:10000000
sum1 = 15.403683
sum2 = 0.693137
Enter a final number:100000000
sum1 = 15.403683
sum2 = 0.693137
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
