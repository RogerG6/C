/* Date：2020/2/13
 * 3-6: 修改itoa函数，使得该函数可以接收三个参数。其中，第三个参数为最小字段宽度。
 *		为了保证转换后所得的结果至少具有第三个参数指定的最小宽度，在必要时应在所得
 *		结果的左边填充一定的空格 
 */ 
 
#include <stdio.h>
#include <string.h>


void reverse(char s[])
{
	int i, j, t;
	
	for (i = 0, j = strlen(s) - 1; i < j; i++, j--)
	{
		t = s[i];
		s[i] = s[j];
		s[j] = t;
	}
}

void itoa(int n, char s[], int len)
{
	int i = 0, j, sign;
	
	if ((sign = n) < 0)
		n = -n;
	
	do
	{
		s[i++] = n % 10 + '0';
	}while ((n /= 10) > 0);
	
	if (sign < 0)
		s[i++] = '-';
	
	/* 填充空格 */ 
	while (i < len)
		s[i++] = ' ';
		
	s[i] = '\0';
	
	reverse(s);
}

int main(void)
{
	int num, len;
	char s[100];
	
	while (1)
	{
		printf("Enter a integar, len: ");
		scanf("%d%d", &num, &len);
		
		itoa(num, s, len);
		printf("%d的%d字段宽的字符串：\n%s\n", num, len, s);		
	}

	return 0;
}

/*
Enter a integar, len: 13 5
13的5字段宽的字符串：
   13
Enter a integar, len: 13 3
13的3字段宽的字符串：
 13
Enter a integar, len: 13 2
13的2字段宽的字符串：
13

*/ 
