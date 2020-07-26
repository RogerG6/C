/* Date：2020/3/23 */ 
/* 1-9：编写一个将输入复制到输出的程序，并将其中连续的多个空格用一个空格代替 */ 

#include <stdio.h>
#define NOTBLANK 'a'

int main(void)
{
	int c, lastc = NOTBLANK;
	
	while ((c = getchar()) != EOF)
	{
		if (c != ' ' || lastc != ' ')
			putchar(c);
		lastc = c;
	}
	
	return 0;
}

/* 结果 ：
＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
a  bc   efg   hi  d d   jk
a bc efg hi d d jk
^Z

--------------------------------
＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝

总结：
	用2个“或”判断，可以处理这一类问题，将多个连续的符号转换为一个 
 */ 
