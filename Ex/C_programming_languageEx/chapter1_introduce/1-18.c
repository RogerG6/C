/* Date��2020/3/24 
 * 1-18����дһ������ɾ��ÿ��������ĩβ�Ŀո��Ʊ������ɾ����ȫ�ǿո����
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
	char current[MAXLEN];	/* ��ǰ�� */ 
	//char longest[MAXLEN];	/* ��� */ 
	
	while ((len = getline(current, MAXLEN)) > 0)
		if (__remove(current) > 0)
			//printf("%s\n", current);
			printstr(current);
	
	return 0;
}

/* ��ӡ�ַ���
 * ��ת���ַ�����ɷ�ת��
 * eg. ���з�����ӡ\n
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

/* ɾ��ÿ��������ĩβ�Ŀո��Ʊ������ɾ����ȫ�ǿո���� */ 
int __remove(char *s)
{
	int i = 0;
	while (s[i] != '\n')		//�ҵ����з� 
		i++;
	i--;
	while (s[i] == ' ' || s[i] == '\t')	// �ҵ����һ���ǿո��Ʊ����char 
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
