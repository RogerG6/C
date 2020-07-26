/* Date：2020/3/23 */ 
/* 1-8: 编写一个统计空格、制表符和换行符个数的程序 */ 

#include <stdio.h>

int main(void)
{
	int space = 0, tab = 0, enter = 0;
	int c;
	
	while ((c = getchar()) != EOF)
	{
		if (c == ' ')
			space++;
		else if (c == '\t')
			tab++;
		else if (c == '\n')
			enter++; 
	}
	
	printf("space = %d, tab = %d, enter = %d\n", space, tab, enter);
	
	return 0;
}

/* 结果：
==============================
abc
efg
hij jk
^Z
space = 1, tab = 1, enter = 3

==============================
总结：
	在windows平台的EOF输入：新一行的开头，输入ctrl + z 

-------------------------------- */ 
