/* Date：2020/3/24
 * 1-16: 修改打印最长文本行的程序的主程序main，使之可以打印任意长度的输入行的长度，并尽可能多地打印文本
 */
#include <stdio.h>

#define MAXLINE 10		//最长行的长度 

int getline(char *line, int lim);
void copys(char *to, char *from);

int main(void)
{
	int len, maxlen = 0;
	char line[MAXLINE];
	char longest[MAXLINE];
	
	while ((len = getline(line, MAXLINE)) > 0)
		if (len > maxlen) {
			maxlen = len;
			copys(longest, line);
		}
		
	if (maxlen > 0)
		printf("longest line : %smaxlen: %d\n", longest, maxlen);
		
	return 0;	
} 

/* 返回任意输入行的长度，并保存尽可能多的输入行内容 */ 
int getline(char *line, int lim)
{
	int i, c;
	int j = 0;
	
	for (i = 0; (c = getchar()) != EOF && c != '\n'; i++)
		if (i < lim - 2)
			line[j++] = c;
	if (c == '\n') {
		line[j++] = c;
		i++;		
	}
	line[j] = '\0';
	return i;
}

/* 将from字符串cpy到to字符串 */ 
void copys(char *to, char *from)
{
	char *p = from;
	while (*p)
		*to++ = *p++;
	*to = '\0';
}
