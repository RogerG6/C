/* Date：2020/2/12
 * 3-3: 编写函数expand(s1, s2)，将字符串s1中类似于a-z之类的速记符号在字符串s2
 *		中拓展为等价的完整列表abc...xyz。
 *		该函数可以处理大小写字母和数字，并可以处理a-b-c、a-z0-9与-a-z等类似情况。
 *		作为前导和尾随的-字符原样排印 
 */ 

#include <stdio.h>
#include <ctype.h>

void expand(char s1[], char s2[])
{
	int i = 0, j = 0;
	char c;
	
	while ((c = s1[i++]) != '\0')
	{
		if (s1[i] == '-' && s1[i+1] >= c)
		{
			i++;
			while (c < s1[i])
				s2[j++] = c++;
		}
		else
			s2[j++] = c;
	}
	s2[j] = '\0';
}

int main(void)
{
	char s1[100], s2[100];
	int i;
	
	printf("Enter a string(a-z, 0-9): \ns1: ");
	gets(s1);
	expand(s1, s2);
	
	printf("s2: %s\n", s2);
	
	return 0;
}

/*
Enter a string(a-z, 0-9):
s1: --..a-g-a-b-d.a-c0-3-a-c---../
s2: --..abcdefg-abcd.abc0123-abc---../

--------------------------------
Process exited after 62.73 seconds with return value 0
请按任意键继续. . .


*/ 
