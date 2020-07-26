# include<stdio.h>
int hello(void);

int i = 0;
int main(void)
{
	while (getchar() != '#')
		printf("hello()被调用的次数为：%d\n", hello());
	
	return 0;
}

int hello(void)
{

	puts("Hello World!");
	i++;
	return i;
}
