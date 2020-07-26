//2018年10月8日 20时45分 
//观察系统如何处理整数、浮点数的上溢和下溢 

# include <stdio.h>
int main(void)
{
	int i;
	float fl;
	double dou;
	
	while(1)
	{
	scanf("%d%e%le", &i, &fl, &dou);
	printf("int：%d\nfloat: %e\ndouble: %le\n", i, fl, dou);
	
	}
	
	return 0;
}
