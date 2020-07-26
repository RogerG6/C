/* Date：2020/3/24
 * 1-17：编写一个程序，打印长度大于80个字符的所有输入行
 */ 
 
#include <stdio.h> 
int getline(char s[], int lim);
void copyline(char to[], char from[]);
#define TARLEN 80	
#define MAXLEN 1000
int main(void) 
{
	int len, max;
	char current[MAXLEN];	/* 当前行 */ 
	//char longest[MAXLEN];	/* 最长行 */ 
	
	while ((len = getline(current, MAXLEN)) > 0)
	{
		if (len > TARLEN)
			printf("%s\n", current);
	}
	
	return 0;
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
