# include <stdio.h>
int main(void)
{
	float f;
	while(1)
	{
		scanf("%f", &f);
		printf("С����ʽ��%f\n", f);
		printf("ָ����ʽ��%e\n", f);
		printf("p��������%a\n", f);
	}
	return 0;
}
