/* Date：2020/3/7 
 * 5-4：编写函数strend(s, t), 如果字符串t出现在字符串s的尾部，该函数返回1，否则返回0
 */ 

#include <stdio.h>

int __strend(char *s, char *t)
{
	char *bs = s;
	char *bt = t;
	
	for (; *s; s++)
		;

	for (; *t; t++)
		;
	
	for (; *s == *t; s--, t--)
		if (s == bs || t == bt)
			break;
			
	/* 相同，移到最开始，2个都不是空str */ 
	if (*s == *t && t == bt && *s != '\0')
		return 1;
	else
		return 0;
}

int main(void)
{
	char *a = "hello world!!!";
	char *b = "ld!!!";
	
	if (__strend(a, b))
		printf("String b 出现在 String a 的尾部\n");
	else
		printf("String b 没有出现在 String a 的尾部\n");
	
	return 0;
}
