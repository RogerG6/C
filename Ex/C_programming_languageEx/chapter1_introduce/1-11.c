/* Date：2020/3/23
 * 1-11：你准备如何测试单词计数程序？如果程序中存在某种错误，那么什么样的输入最可能发现这类错误？
 */ 
 
/* 书中p14页的单词计数程序 */ 
#include <stdio.h>
#define IN 1
#define OUT 0
int main(void)
{
	int nl, nw, nc, c;
	int state = OUT;
	
	nl = nw = nc = 0;
	while ((c = getchar()) != EOF){
		nc++;
		if (c == '\n')
			nl++;
		if (c == ' ' || c == '\n' || c == '\t')
			state = OUT;
		else if (state == OUT){
			state = IN;
			nw++;
		}
	}
	printf("nl = %d, nw = %d, nc = %d\n", nl, nw, nc);
	return 0;	
} 

/* 那些满足边界条件的输入情况最有助于发现单词计数程序的错误：
 *		没有输入
 *		没有单词(只有换行符) 
 *		没有单词(只有空格，制表符，换行符)
 *		每个单词各占一行的情况
 *		单词出现于文件本首的情况
 *		单词出现于一串空格之后的情况
 */ 

