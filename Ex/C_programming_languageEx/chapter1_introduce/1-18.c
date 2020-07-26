/* Date：2020/3/24 
 * 1-18：编写一个程序，删除每个输入行末尾的空格及制表符，并删除完全是空格的行
 */ 
 
#include <stdio.h>
#include <string.h> 
#define TARLEN 80	
#define MAXLEN 1000

int __remove(char *s);
int getline(char s[], int lim);
void copyline(char to[], char from[]);
void printstr(char *s);


int main(void) 
{
	int len, max;
	char c;
	char current[MAXLEN];	/* 当前行 */ 
	//char longest[MAXLEN];	/* 最长行 */ 
	
	while ((len = getline(current, MAXLEN)) > 0)
		if (__remove(current) > 0)
			//printf("%s\n", current);
			printstr(current);
	
	return 0;
}

/* 打印字符串
 * 将转义字符输出成非转义
 * eg. 换行符，打印\n
 */ 
void printstr(char *s)
{
	int i;
	for (i = 0; s[i]; i++)
		if (s[i] == '\t')
			printf("\\t");
		else if (s[i] == '\n')
			printf("\\n");
		else
			putchar(s[i]);
	putchar('\n');
}

/* 删除每个输入行末尾的空格及制表符，并删除完全是空格的行 */ 
int __remove(char *s)
{
	int i = 0;
	while (s[i] != '\n')		//找到换行符 
		i++;
	i--;
	while (s[i] == ' ' || s[i] == '\t')	// 找到最后一个非空格、制表符的char 
		i--;
	if (i >= 0) {
		s[++i] = '\n';
		s[++i] = '\0';
	}
	return i;
}

int getline(char s[], int lim)
{
	int i, j = 0;
	char c;
	
	for (i = 0; ((c = getchar()) != EOF) && c != '\n'; i++)
		if (i < lim - 2) 
			s[j++] = c;
	if (c == '\n') {
		s[j++] = c;
		i++;
	}
	
	s[j] = '\0';
	return i;
}

void copyline(char to[], char from[])
{
	int i = 0;
	while ((to[i] = from[i]) != '\0')
		i++;
}
