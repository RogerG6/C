/* Date：2020/3/4
 * 4-13：写一个递归版本的reverse(s)函数，以将字符串倒置
 */ 

# include <stdio.h>

void reverse(char s[])
{
	int c;
	static int i = 0, j = 0;
	
	if (s[i] == '\0')	
		return;
	
	c = s[i++];
	reverse(s);
	
	s[j++] = c;
	s[j] = '\0';	
}

int main(void)
{
	char s[100];
	
	printf("请输入一个字符串：");
	scanf("%s", &s);
	
	reverse(s);
	
	printf("Reversed: %s\n", s);
	
	return 0;
}

/*
请输入一个字符串：123sdaf52d
Reversed: d25fads321

--------------------------------
Process exited after 4.731 seconds with return value 0
请按任意键继续. . .

*/ 
