# include <stdio.h>
# include <ctype.h>
float get_num(void);
char get_char(void);

int main(void)
{
	char ch;
	float ft, sed;
	printf("Enter the operation of your choice：\n");
	printf("a. add                s. subtract\n");
	printf("m. multiply           d. divide\nq. quit\n");
	scanf("%c", &ch);
	while (getchar() != '\n')  //只取首字符 
		continue;
	
	while (ch != 'q')   
	{
		if (!(ch == 'a' || 's' == ch || 'm' == ch || 'd' == ch ) )
		{
			printf("Please enter a right choice!\n");
			ch = get_char();
			continue;
		}
		printf("Enter first number:");
		ft = get_num();
		printf("Enter second number:");
		sed = get_num();
		
		switch(ch)
		{
			case 'a': printf("%f + %f = %f\n", ft, sed, ft + sed);
					  break;
			case 's': printf("%f - %f = %f\n", ft, sed, ft - sed);
					  break;
			case 'm': printf("%f * %f = %f\n", ft, sed, ft * sed);
					  break;
			case 'd': while (sed == 0)
					  {
					  	  printf("Enter a number other than 0:");
					  	  sed = get_num();
					  }
					  printf("%f / %f = %f\n", ft, sed, ft / sed);
					  break;
		}
		printf("Enter the operation of your choice：\n");
		printf("a. add                s. subtract\n");
		printf("m. multiply           d. divide\nq. quit\n");
		ch = get_char();
	}
	return 0;
}

float get_num(void)   //读取数字 
{
	float i;
	char ch;
	while (scanf("%f", &i) != 1)
	{
		while ((ch = getchar()) != '\n') //只取字符，去掉空字符
			putchar(ch);
		printf(" is not a number\n");
		printf("Please enter a number, such as 2.5, -1.78E8, or 3:");
	}
	
	return i;
}

char get_char(void)  //读取字符 
{
	char ch;
	
	scanf("%c", &ch);

	while (isspace(ch))  //跳过空白符 
		scanf("%c", &ch);
	while (getchar() != '\n')  //只取首字符 
		continue;
			
	return ch;
}
