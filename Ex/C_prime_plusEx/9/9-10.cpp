# include <stdio.h>

void to_base_n(int, int);

int main(void)
{
	int n, x;
	
	printf("������һ��ʮ��������ת����Ŀ����ƣ�");
	while(scanf("%d%d", &n, &x) == 2 && (x > 1 && x < 11))   //������2~10֮�� 
	{
		printf("%d ��%d������Ϊ��", n, x);
		to_base_n(n, x);
		printf("\n\n������һ��ʮ��������ת����Ŀ����ƣ�");
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

