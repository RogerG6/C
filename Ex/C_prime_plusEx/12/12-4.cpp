# include<stdio.h>
int hello(void);

int i = 0;
int main(void)
{
	while (getchar() != '#')
		printf("hello()�����õĴ���Ϊ��%d\n", hello());
	
	return 0;
}

int hello(void)
{

	puts("Hello World!");
	i++;
	return i;
}
