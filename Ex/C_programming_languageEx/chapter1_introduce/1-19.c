/* Date：2020/3/23
 * 1-19：编写函数reverse(s)将字符串中的字符顺序颠倒过来。使用该函数编写一个程序，每次颠倒一个输入行中的字符顺序
 */ 
 
#include <stdio.h>
#include <string.h> 
#define MAXLEN 1000

int getline(char s[], int lim);
void reverse(char *s);

int main(void) 
{
	char s[MAXLEN];

	while (getline(s, MAXLEN) > 0){
		reverse(s);
		printf("reversed: %s\n", s);
	}
	
	return 0;
}

void reverse(char *s)
{
	int i = 0, j, tmp;
	
	while (s[i] != '\0')
		i++;
	i--;
	
	if (s[i] == '\n')
		i--;
		
	j = 0;
	while (j < i) {
		tmp = s[i];
		s[i] = s[j];
		s[j] = tmp;
		
		j++;
		i--;
	}
}


int getline(char s[], int lim)
{
	int i;
	char c;
	
	for (i = 0; i < lim - 2 && ((c = getchar()) != EOF) && c != '\n'; i++)
		s[i] = c;
	
	if (c == '\n')
		s[i++] = c;
	s[i] = '\0';
	return i;
}


/*
运行结果：
abcdefg
Approch 1 reversed string : gfedcba
Approch 2 reversed string : gfedcba

--------------------------------
Process exited after 3.144 seconds with return value 0
请按任意键继续. . .
 
*/ 
