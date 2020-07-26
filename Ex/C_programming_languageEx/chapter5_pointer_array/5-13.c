/* Date��2020/3/10 
 * 5-13����д����tail�����������е����n�д�ӡ������Ĭ������£�n��ֵΪ10��������ͨ��һ����ѡ�����ı�n��ֵ����ˣ����
 *	  tail -n
 *	  ����ӡ����������n�С����������n��ֵ�Ƿ�����ó������������С���д�ĳ���Ҫ������ô洢�ռ䣻����Ĵ洢��ʽ
 *	  Ӧ��ͬ5.6�����������Ĵ洢��ʽһ�����������ù̶����ȵĶ�ά���顣
 */ 
#include <stdio.h>
#include <string.h>
#include <stdlib.h> 

#define MAXLINES 500	//��������� 
#define MAXLEN   1000	//һ��������볤�� 
#define DEFLINES  10

int readlines(char *lineptr[], int maxlines);
int getline(char *line, int maxlen);


int main(int argc, char *argv[])
{
	int i;
	int n;		//��ӡ������
	int nlines = 0;		// ����������� 
	int len;	 
	int first;	//���n���е�һ�е����� 
	int last;	// ���һ��str��ָ������� 
	char *p;
	char *buf;	//ָ��洢�ַ����Ļ����� 
	char *bufend;
	char line[MAXLEN];
	char *lineptr[MAXLINES] ;
	
	// �ж�agrc����� 
	if (argc == 1)
		n = DEFLINES;
	else if (argc == 2 && argv[1][0] == '-') 
		n = atoi(argv[1] + 1);
	else
	{
		printf("Usage: tail -n\n");
		return -1;
	}
	
	// �ж�n�ĺϷ���  
	if (n < 1 || n > MAXLINES)
		n = MAXLINES;
		
	// ��ʼ��lineptr
	for (i = 0; i < MAXLINES; i++) 
		lineptr[i] = NULL;
		
	// ����buf�Ŀռ�
	if ((p = buf = malloc(MAXLINES * MAXLEN)) == NULL) 
	{
		printf("error: can't alloc memory\n");
		return -1;
	}
	
	last = 0;
	bufend = buf + MAXLINES * MAXLEN;
	
	// ����
	while ((len = getline(line, MAXLEN)) > 0)
	{
		//printf("Here\n");	
		if ((p + len + 1) >= bufend) 
			p = buf;			// ѭ�����
		strcpy(p, line);
		lineptr[last] = p;
		if (++last >= MAXLINES)
			last = 0;			// ѭ�����
		p += len + 1;
		nlines++;
	}
	
	// n��nlines�Ƚ�
	if (n > nlines) 
		n = nlines;
	
	// ��ӡ����n��
	first =  last - n;
	if (first < 0) 
		first += MAXLINES;
	
	for (i = first; n--; i = (i + 1) % MAXLINES)
		printf("%s", lineptr[i]);
		
	return 0;
}



int getline(char *line, int maxlen)
{
	int c, i;
	
	for (i = 0; i < maxlen - 2 && (c = getchar()) != EOF && c != '\n'; i++) 
		line[i] = c;
	
	if (c == '\n')
		line[i++] = c;
	
	line[i] = '\0';
		
	return i;
}


