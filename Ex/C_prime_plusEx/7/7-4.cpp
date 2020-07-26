# include <stdio.h>
int main(void)
{
	int fp = 0;  //定义句号（full point）的个数 
	int ep = 0;  //定义感叹号（ exclamatory point）的个数 
	char c;
	
	while ((c = getchar()) != '#') 
	{
		if ('!' == c || '.' == c)
		{
			if('!' == c)
			{
				printf("!!");
			    ep++;
			}
			else
			{
				putchar('!');
				fp++;
			}
		}
		else
			putchar(c);
	}
	printf("\n一共替换了 %d 次！\n", fp + ep);
	
	return 0;
}
