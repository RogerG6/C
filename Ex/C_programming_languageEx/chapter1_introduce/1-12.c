/* Date：2020/3/23
 * 1-12: 编写一个程序，以每行一个单词的形式打印输入
 */ 
#include <stdio.h>
#define IN 1
#define OUT 0
 
int main(void)
{
	int c, lastc;
	int state = OUT;
	
	lastc = ' ';
	while ((c = getchar()) != EOF)
		if (c == ' ' || c == '\t' || c == '\n') {
			if (state == IN){
				putchar('\n');
				state = OUT;
			}
		}	
		else if (state == OUT){
			state = IN;
			putchar(c);
		}else
			putchar(c);
	
	return 0;
}

/* 结果：
＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝ 
  so you are   a  b o y !
so
you
are
a
b
o
y
!
^Z

-------------------------------- 
＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
*/ 
