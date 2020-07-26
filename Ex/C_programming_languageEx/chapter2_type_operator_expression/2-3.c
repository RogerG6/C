/* Date：2020/2/11 
 * 2-3: 编写函数htoi(s), 把由16进制数字组成的字符串(包含可选的前缀0x或0X)转换为与之等价的整型值。 
 *		字符串中允许包含的数字包括：0~9、A~f、a~f 
 */

#include <stdio.h>

#define YES 1
#define NO  0

int htoi(char s[])
{
	int i = 0, num = 0, digt, inhex;	/* inhex判断输入的16进制数是否合法 */ 
	
	if (s[i] == '0')
	{
		i++;
		if (s[i] == 'x' || s[i] == 'X')
			++i;
	}
	
	for(inhex = YES; inhex == YES; i++)
	{
		if (s[i] >= '0' && s[i] <= '9')
			digt = s[i] - '0';
		else if (s[i] >= 'A' && s[i] <= 'F')
			digt = s[i] - 'A' + 10;
		else if (s[i] >= 'a' && s[i] <= 'f')
			digt = s[i] - 'a' + 10;
		else
			inhex = NO;
		
		if (inhex == YES)
			num = 16 * num + digt;
	}
	return num;
}

int main(void)
{
	char hex[100];
	
	printf("请输入一个16进制数：");
	gets(hex);
	
	printf("16进制的%s的10进制：%d\n", hex, htoi(hex));	

	return 0;
}

/* ===================================================================== */ 

#if 0 
int htoi_without_0x(char s[])
{
	int i, num = 0, t;
	
	for (i = 0; s[i] != '\0'; i++)
	{
		if (s[i] >= '0' && s[i] <= '9')
			t = s[i] - '0';
		
		if (s[i] >= 'a' && s[i] <= 'f')
			t = s[i] - 'a' + 10;
			
		num = num * 16 + t;
		
		//printf("num = %d\n", num);
	}
	
	return num;
}

int htoi(char s[])
{
	if (s[0] == '0' && s[1] == 'x')
		return htoi_without_0x(&s[2]);
	else
		return htoi_without_0x(s);
}

int main(void)
{
	char hex[100];
	int i;
	
	
	while (1)
	{
		printf("请输入一个16进制数：");
		gets(hex);
		if (hex[0] == 'q' || hex[0] == 'Q')
			break;
		
		/* 转换成小写 */ 
		for (i = 0; hex[i] != '\0'; i++)
			hex[i] = tolower(hex[i]);
			
		printf("16进制的%s的10进制：%d\n", hex, htoi(hex));	
	}
	return 0;
}

#endif


