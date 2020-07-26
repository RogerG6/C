/* Date：2020/2/15
 * 4-1: 编写函数strrindex(s, t)，它返回字符串t在s中最右边出现的位置
 *		如果s中不包含t，则返回-1 
 */ 
 
#include <stdio.h>

int strrindex(char s[], char t[])
{
	int i, j, k, right = -1;
	
	for (i = 0; s[i] != '\0'; i++)
	{
		for (j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++)
			;
		if (t[k] == '\0')
			right = i;
	}
	return right;
}

int main(void)
{
	char t[] = "ould";
	char s[100];
	int num;
	
	printf("Enter a string: ");
	gets(s);
	
	num = strrindex(s, t);
	if (num >= 0)
		printf("s[]中有t[]\n第%d个字符\n", num + 1);
	else
		printf("s[]中无t[]\n");
			
	return 0;
}

/*
Enter a string: would u could u
s[]中有t[]
第10个字符

--------------------------------
Process exited after 13.01 seconds with return value 0
请按任意键继续. . .
*/ 
