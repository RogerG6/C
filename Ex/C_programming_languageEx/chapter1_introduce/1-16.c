/* Date��2020/3/24
 * 1-16: �޸Ĵ�ӡ��ı��еĳ����������main��ʹ֮���Դ�ӡ���ⳤ�ȵ������еĳ��ȣ��������ܶ�ش�ӡ�ı�
 */
#include <stdio.h>

#define MAXLINE 10		//��еĳ��� 

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

/* �������������еĳ��ȣ������澡���ܶ������������ */ 
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

/* ��from�ַ���cpy��to�ַ��� */ 
void copys(char *to, char *from)
{
	char *p = from;
	while (*p)
		*to++ = *p++;
	*to = '\0';
}
