/* Date��2020/3/7 
 * 5-4����д����strend(s, t), ����ַ���t�������ַ���s��β�����ú�������1�����򷵻�0
 */ 

#include <stdio.h>

int __strend(char *s, char *t)
{
	char *bs = s;
	char *bt = t;
	
	for (; *s; s++)
		;

	for (; *t; t++)
		;
	
	for (; *s == *t; s--, t--)
		if (s == bs || t == bt)
			break;
			
	/* ��ͬ���Ƶ��ʼ��2�������ǿ�str */ 
	if (*s == *t && t == bt && *s != '\0')
		return 1;
	else
		return 0;
}

int main(void)
{
	char *a = "hello world!!!";
	char *b = "ld!!!";
	
	if (__strend(a, b))
		printf("String b ������ String a ��β��\n");
	else
		printf("String b û�г����� String a ��β��\n");
	
	return 0;
}
