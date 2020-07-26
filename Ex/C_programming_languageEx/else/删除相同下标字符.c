/* Date：2020/2/11 
 * 编写函数squeeze(s1, s2): 
 *		字符串s1与字符串s2相同下标的字符相同的话，则删除s1中相应的字符 
 */
 
#include <stdio.h>

int main(void)
{
	char s1[100], s2[100];
	int i, j;
	
	
	while (1)
	{
		printf("请输入s1：");
		gets(s1);
		printf("请输入s2：");
		gets(s2);
		
		i = j = 0;
		while(1)
		{
			/* 相等则跳过，不相等则将i指向的值赋给j指向的值 */ 
			if (s1[i] != s2[i])
			{
				s1[j] = s1[i];
				j++; 
			}
			i++;
			
			/* s2长度大于等于s1 */ 
			if (s1[i] == '\0')
			{	
				s1[j] = '\0';
				break;
			}
		
			/* s2长度小于s1 */ 
			if (s2[i] == '\0')
			{
				while ((s1[j++] = s1[i++]) != '\0');
				break;
			}
		}
		
		printf("去重后：\ns1: %s\ns2: %s\n", s1, s2)	;
			
	}
		
	return 0;
}
 
