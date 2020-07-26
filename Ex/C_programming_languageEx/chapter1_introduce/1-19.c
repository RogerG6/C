/* Date��2020/3/23
 * 1-19����д����reverse(s)���ַ����е��ַ�˳��ߵ�������ʹ�øú�����дһ������ÿ�εߵ�һ���������е��ַ�˳��
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
���н����
abcdefg
Approch 1 reversed string : gfedcba
Approch 2 reversed string : gfedcba

--------------------------------
Process exited after 3.144 seconds with return value 0
�밴���������. . .
 
*/ 
