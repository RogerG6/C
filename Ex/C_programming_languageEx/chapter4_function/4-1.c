/* Date��2020/2/15
 * 4-1: ��д����strrindex(s, t)���������ַ���t��s�����ұ߳��ֵ�λ��
 *		���s�в�����t���򷵻�-1 
 */ 
 
#include <stdio.h>

int strrindex(char s[], char t[])
{
	int i, j, k, right = -1;
	
	for (i = 0; s[i] != '\0'; i++)
	{
		for (j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++)
			;
		if (t[k] == '\0')
			right = i;
	}
	return right;
}

int main(void)
{
	char t[] = "ould";
	char s[100];
	int num;
	
	printf("Enter a string: ");
	gets(s);
	
	num = strrindex(s, t);
	if (num >= 0)
		printf("s[]����t[]\n��%d���ַ�\n", num + 1);
	else
		printf("s[]����t[]\n");
			
	return 0;
}

/*
Enter a string: would u could u
s[]����t[]
��10���ַ�

--------------------------------
Process exited after 13.01 seconds with return value 0
�밴���������. . .
*/ 
