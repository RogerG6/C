/* Date：2020/2/11 
 * 2-10: 重新编写将大写字母转换成小写字母的函数lower，并用条件表达式替代其中的if else结构 
 */ 
#include <stdio.h>

int lower(int c)
{
	return (c >= 'A' && c <= 'Z' ? c-'A'+'a' : c);
}

int main(void)
{
	char str[100] = "HELLOWORld";
	int i;
	
	for (i = 0; str[i] != '\0'; i++) 
	{
		str[i] = lower(str[i]);
	}
	
	printf("string: %s\n", str);
	
	return 0;
}

/*
string: helloworld

--------------------------------
Process exited after 0.1911 seconds with return value 0
请按任意键继续. . .

*/ 
