/* Date：2020/3/4 
 * 4-12：运用printd函数的设计思想编写一个递归版本的itoa函数，即通过递归调用把整数转换成字符串
 */ 

#include <stdio.h>
#define abs(x) ((x > 0) ? (x) : (-x))


void itoa(char s[], int n)
{
	static int i;
	
	if (n / 10)
		itoa(s, n / 10);
	else
	{
		i = 0;
		if (n < 0)
			s[i++] = '-';
	}
	s[i++] = abs(n) % 10 + '0';
	s[i] = '\0';		//之前的'\0' 会被覆盖 
}

int main(void)
{
	int num;
	char a[100];
	
	printf("请输入一个整数：");
	scanf("%d", &num);
	
	itoa(a, num);
	printf("%d 转换成字符串：%s\n", num, a);
	
	
	return 0;
}
