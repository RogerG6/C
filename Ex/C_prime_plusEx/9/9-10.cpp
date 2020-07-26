# include <stdio.h>

void to_base_n(int, int);

int main(void)
{
	int n, x;
	
	printf("请输入一个十进制数和转换的目标进制：");
	while(scanf("%d%d", &n, &x) == 2 && (x > 1 && x < 11))   //进制在2~10之间 
	{
		printf("%d 的%d进制数为：", n, x);
		to_base_n(n, x);
		printf("\n\n请输入一个十进制数和转换的目标进制：");
	}
	
	return 0;
}

void to_base_n(int i, int j)
{
	int r;
	
	r = i % j;

	if (i >= j)
		to_base_n(i/j, j);
	
	printf("%d", r);
}

