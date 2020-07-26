# include <stdio.h>
int main(void)
{
	int i, j;
	char n, ch;
	
	printf("请输入一个大写字母：");
	scanf("%c", &n); 
	
	for (i = 1; i <= n-'A'+1; i++)     //打印的行数 
	{
		for(j = 1; j <= n-'A'+1-i; j++)  //打印字母前的空格 
		{
			printf(" ");
		}
		for (j = 1, ch = 'A'; j <= i; j++)  //打印顺序的字母 
		{
			printf("%c", ch++);
		}
		ch -= 2;
		for(; j <= 2*i-1; j++)    //打印倒序的字母 
		{
			printf("%c", ch--);
		}
		printf("\n");
	}   
	return 0;
}
