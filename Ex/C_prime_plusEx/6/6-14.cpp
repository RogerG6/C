# include <stdio.h>
int main(void) 
{
	double a[8], b[8];
	int i;
	double sum = 0.0;
	
	for(i = 0; i < 8; i++)
	{
		scanf("%lf", &a[i]);
		sum = sum + a[i];
		b[i] = sum;
		printf("%7.3lf ", a[i]);
	}
	getchar();   //处理缓冲区中最后一个 ‘\n’ 
	printf("\n");
	for(i = 0; i < 8; i++)
	{
		printf("%7.3lf ", b[i]);
	}
		
	 
	return 0;
}
