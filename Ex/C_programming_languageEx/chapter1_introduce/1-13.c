/* Date：2020/3/23 
 * 1-13: 编写一个程序，打印输入中单词长度的直方图。水平方向的直方图比较容易绘制，垂直方向的直方图则要困难一些
 */ 
 
#include <stdio.h> 
#define IN  1	/* 在单词中 */ 
#define OUT 0	/* 在单词外 */ 
#define MAXWL	26	/* 最大单词长度 */ 



int main(void) 
{
	int i, c, state = OUT, c_cnt = 0;
	int word_len[MAXWL];
	
	for (i = 1; i <= MAXWL; i++)
		word_len[i] = 0;
	
	while ((c = getchar()) != EOF)
	{
		if (c < 'A' || c > 'z')	/* 单词的末尾 */ 
		{
			if (state == IN)
			{
				word_len[c_cnt]++;
				c_cnt = 0;
				state = OUT;
			}
			
		}
		else if (state == OUT)	/* 单词的开始 */ 
		{
			if (c >= 'A' && c <= 'z')
				c_cnt++;
			state = IN;
		}
		else	/* 在单词中 */ 
		{
			if (c >= 'A' && c <= 'z')
				c_cnt++; 
		}
			
	}
	
	for (i = 1; i <= MAXWL; i++)
	{
		printf("%2d : ", i);
		for (int j = 0; j < word_len[i]; j++)	
			putchar('|');
		putchar('\n');
	}
	return 0;
}


/* 结果：
============================================
The boy is very handsome
and the girl is also very beautiful
Do you agree with me?
^Z
 1 :
 2 : ||||
 3 : |||||
 4 : |||||
 5 : |
 6 :
 7 :
 8 : |
 9 : |
10 :
11 :
12 :
13 :
14 :
15 :
16 :
17 :
18 :
19 :
20 :
21 :
22 :
23 :
24 :
25 :
26 :
============================================*/ 
