# include <stdio.h>

int main(void)
{
	int low, up, i;
	
	printf("请输入下限和上限："); 
	scanf("%d %d", &low, &up);
	printf("数值         平方           立方\n");
	for (i = low; i <= up; i++)
		printf("%2d        %5d        %8d\n", i, i*i, i*i*i);
	
	return 0;
	
}
