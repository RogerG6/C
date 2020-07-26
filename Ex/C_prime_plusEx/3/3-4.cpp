# include <stdio.h>
int main(void)
{
	float f;
	while(1)
	{
		scanf("%f", &f);
		printf("小数形式：%f\n", f);
		printf("指数形式：%e\n", f);
		printf("p计数法：%a\n", f);
	}
	return 0;
}
