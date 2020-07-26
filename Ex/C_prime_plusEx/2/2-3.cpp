# include <stdio.h>

int main(void)
{
	int age;
	
	printf("请输入您的年龄：");
	scanf("%d", &age);
	printf("您的年龄转换成天数为 %d 天\n", age*365) ;
	
	return 0;
}
