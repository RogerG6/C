/* Date��2020/2/12
 * 2-4: ��дһ������squeeze(s1, s2)�����ַ���s1���κ����ַ���s2���ַ�ƥ����ַ���ɾ�� 
 *
 */ 
 
#include <stdio.h>

void squeeze(char s1[], char s2[])
{
	int i, j, k;
	
	for (i = k = 0; s1[i] != '\0'; i++)
	{
		for (j = 0; s2[j] != '\0' && s2[j] != s1[i]; j++)
			;
		
		if (s2[j] == '\0')
			s1[k++] = s1[i];
	}
	s1[k] = '\0';
}

int main(void)
{
	char s1[100], s2[100];
	
	printf("������s1��");
	gets(s1);
	printf("������s2��");
	gets(s2);
	
	squeeze(s1, s2);
	
	printf("ȥ�غ�\ns1: %s\ns2: %s\n", s1, s2);
	
	return 0;
}

/*
������s1��abcdefg
������s2��hijadezk
ȥ�غ�
s1: bcfg
s2: hijadezk

--------------------------------
Process exited after 15.73 seconds with return value 0
�밴���������. . .


*/ 
