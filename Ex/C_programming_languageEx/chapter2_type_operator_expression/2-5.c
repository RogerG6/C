/* Date��2020/2/11 
 * 2-5: ��д����any(s1, s2)�����ַ���s2�е���һ�ַ����ַ���s1�е�һ�γ��ֵ�λ����Ϊ������ء����s1�в�����s2��
 * 		���ַ����򷵻�-1��(��׼����strpbrk����ͬ���Ĺ��ܣ�ֻ�������ص���ָ���λ�õ�ָ��) 
 */ 

#include <stdio.h>

int any(char s1[], char s2[]) 
{
	int i, j;
	
	for (i = 0; s2[i] != '\0'; i++)
	{
		for (j = 0; s1[j] != '\0'; j++)
			if (s1[j] == s2[i])
				return j;
	}
	
	return -1;	
}

int main(void) 
{
	char s1[100], s2[100];
	int i, j;
	
	printf("������s1��");
	gets(s1);
	printf("������s2��");
	gets(s2);
	
	
	printf("s1�� %s s2������\n", any(s1, s2)== -1 ? "��" : "��"); 
	
	return 0;
}

/*
������s1��abcdefg
������s2��hijklmn
s1�� �� s2������

--------------------------------
Process exited after 10.08 seconds with return value 0
�밴���������. . .
*/ 
