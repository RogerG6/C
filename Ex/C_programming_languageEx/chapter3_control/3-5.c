/* Date：2020/2/12
 * 3-5: 编写函数itob(n, s, b)，将整数n转换为以b为底的数，并将转换结果以字符的形式
 *		保存到字符串s中。
 *		eg. itob(n, s, 16)把整数n格式化成16进制整数保存到s中 
 */ 
 
#include <stdio.h>
#include <string.h>

char hex[16] = {
	'0',
	'1',
	'2',
	'3',
	'4',
	'5',
	'6',
	'7',
	'8',
	'9',
	'a',
	'b',
	'c',
	'd',
	'e',
	'f',	
};

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

void itob(int n, char s[], int b)
{
	int i = 0, sign;
	
	if ((sign = n) < 0)
		n = -n;
	
	do
	{
		s[i++] = hex[n % b];
	}while ((n /= b) > 0);
	
	if (sign < 0)
		s[i++] = '-';
	s[i] = '\0';
	
	reverse(s);
}

int main(void)
{
	int num, base;
	char s[100];
	
	while (1)
	{
		printf("Enter a integar, a base: ");
		scanf("%d%d", &num, &base);
		
		itob(num, s, base);
		printf("%d(10) = %s(%d)\n", num, s, base);		
	}

	return 0;
}

/*
Enter a integar, a base: 234 2
234(10) = 11101010(2)
Enter a integar, a base: 234 8
234(10) = 352(8)
Enter a integar, a base: 234 10
234(10) = 234(10)
Enter a integar, a base: 234 16
234(10) = ea(16)

*/ 
