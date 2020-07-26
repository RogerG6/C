/* Date：2020/2/11 
 * 2-5: 编写函数any(s1, s2)，将字符串s2中的任一字符在字符串s1中第一次出现的位置作为结果返回。如果s1中不包含s2中
 * 		的字符，则返回-1。(标准库中strpbrk具有同样的功能，只是它返回的是指向该位置的指针) 
 */ 

#include <stdio.h>

int any(char s1[], char s2[]) 
{
	int i, j;
	
	for (i = 0; s2[i] != '\0'; i++)
	{
		for (j = 0; s1[j] != '\0'; j++)
			if (s1[j] == s2[i])
				return j;
	}
	
	return -1;	
}

int main(void) 
{
	char s1[100], s2[100];
	int i, j;
	
	printf("请输入s1：");
	gets(s1);
	printf("请输入s2：");
	gets(s2);
	
	
	printf("s1中 %s s2的内容\n", any(s1, s2)== -1 ? "无" : "有"); 
	
	return 0;
}

/*
请输入s1：abcdefg
请输入s2：hijklmn
s1中 无 s2的内容

--------------------------------
Process exited after 10.08 seconds with return value 0
请按任意键继续. . .
*/ 
