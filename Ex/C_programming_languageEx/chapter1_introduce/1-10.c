/* Date：2020/3/23
 * 1-10: 编写一个将输入复制到输出的程序，并将其中的制表符替换为\t，把回退符替换为\b，把反斜杠替换为\\，
 *	     这样可以将制表符和回退符以可见的方式显示出来
 */ 


#include <stdio.h>
//#define NOTBLANK 'a'

int main(void)
{
	int c;//lastc = NOTBLANK;
	
	while ((c = getchar()) != EOF)
	{
		if (c == '\t')
			printf("\\t");
		else if (c == '\b')
			printf("\\b");
		else if (c == '\\')
			printf("\\\\");
		else
			putchar(c);
	}
	
	return 0;
}


/* 结果：
=================================
abcd    dkfj
abcd\tdkfj\t
ab\\df\df\f\f
ab\\\\df\\df\\f\\f
^Z

--------------------------------
====================================
 */ 
