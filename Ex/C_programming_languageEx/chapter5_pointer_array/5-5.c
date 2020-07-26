/* Date��2020/3/7 
 * 5-5��ʵ�ֿ⺯��strncpy, strncat, strncmp���������Բ����ַ����е�ǰn���ַ����в��������磺����strncpy(s, t, n)
 *      ��t�����ǰn���ַ����Ƶ�s�У�����ϸ��˵����μ���¼B
 */ 
 
#include <stdio.h>
#include <string.h>

void __strncpy(char *s, char *t, int n) 
{
	while (*t && n-- > 0)
		*s++ = *t++;
	
	/* ���t�в���n��Ԫ�أ�����sĩβ���'\0' */ 
	while (n-- > 0)
		*s++ = '\0';
}

void __strncat(char *s, char *t, int n)
{
	__strncpy(s + strlen(s), t, n);
}

/* ǰn���ַ��Ƚ� �������ַ����� 
 * s < t : ���� 
 * s > t : ���� 
 * s = t : 0 
 */ 
int __strncmp(char *s, char *t, int n)
{
	for (; *s == *t; s++, t++)
		/* ����s��t��ĩβ �� �Ƚ���n���ַ����򷵻� */ 
		if (*s == '\0' || --n <= 0)
			return 0;
	return *s - *t;
}

int main(void)
{
	char s[100];
	char *cpy = "hello world!";
	char *cat = "I am rogerg6.";
	char *cmp = "helk.";
	int len;
	
	__strncpy(s, cpy, 12);
	printf("string s: %s\n", s);
	
	__strncat(s, cat, 15);
	printf("string s: %s\n", s);

	printf("s �� cmp ǰ4���ַ���%sһ����\n�ַ����ࣺ%d\n", (len = __strncmp(s, cmp, 4)) ? "��" : "", len);

	
	
	return 0;
}
