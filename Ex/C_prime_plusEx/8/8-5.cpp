//2018年10月20日 12时19分
//猜数字 
# include <stdio.h> 
# include <ctype.h>
# define LOWER 1
# define UPPER 1000 
int main(void)
{
	int guess;
	int n = 1;
	int lower = LOWER, upper = UPPER;
	char ch;
	
	printf("请输入您选的数："); 
	scanf("%d", &guess);
	while (!(guess >= LOWER && guess <= UPPER)) 
	{
		printf("请输入正确的数字范围：");
	    scanf("%d", &guess);
	}
		
	
	printf("现在我要猜了！\n");
	printf("如果猜小了就输入s，如果猜大了就输入b, 如果猜对了就输入y!\n");
	printf("它是%d ？\n", n);
	
	
	while (1)
	{
		while(isspace(ch = getchar()) ) //跳过所有空白符 
			continue;
		if (ch == 'y')
		{
			printf("你猜对了!\n");
			break;
		}
		if (ch == 's')
		{
			lower = n;
		}
		if (ch == 'b')
		{
			upper = n;
		}
		n = (lower + upper) / 2;
		printf("它是%d ？\n", n);
	}
	
	return 0;
}
