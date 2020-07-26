/* Date：2020/2/12
 * 2-4: 编写一个函数squeeze(s1, s2)，将字符串s1中任何与字符串s2中字符匹配的字符都删除 
 *
 */ 
 
#include <stdio.h>

void squeeze(char s1[], char s2[])
{
	int i, j, k;
	
	for (i = k = 0; s1[i] != '\0'; i++)
	{
		for (j = 0; s2[j] != '\0' && s2[j] != s1[i]; j++)
			;
		
		if (s2[j] == '\0')
			s1[k++] = s1[i];
	}
	s1[k] = '\0';
}

int main(void)
{
	char s1[100], s2[100];
	
	printf("请输入s1：");
	gets(s1);
	printf("请输入s2：");
	gets(s2);
	
	squeeze(s1, s2);
	
	printf("去重后：\ns1: %s\ns2: %s\n", s1, s2);
	
	return 0;
}

/*
请输入s1：abcdefg
请输入s2：hijadezk
去重后：
s1: bcfg
s2: hijadezk

--------------------------------
Process exited after 15.73 seconds with return value 0
请按任意键继续. . .


*/ 
