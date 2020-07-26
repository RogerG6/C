/* Date��2020/2/13
 * 3-6: �޸�itoa������ʹ�øú������Խ����������������У�����������Ϊ��С�ֶο�ȡ�
 *		Ϊ�˱�֤ת�������õĽ�����پ��е���������ָ������С��ȣ��ڱ�ҪʱӦ������
 *		�����������һ���Ŀո� 
 */ 
 
#include <stdio.h>
#include <string.h>


void reverse(char s[])
{
	int i, j, t;
	
	for (i = 0, j = strlen(s) - 1; i < j; i++, j--)
	{
		t = s[i];
		s[i] = s[j];
		s[j] = t;
	}
}

void itoa(int n, char s[], int len)
{
	int i = 0, j, sign;
	
	if ((sign = n) < 0)
		n = -n;
	
	do
	{
		s[i++] = n % 10 + '0';
	}while ((n /= 10) > 0);
	
	if (sign < 0)
		s[i++] = '-';
	
	/* ���ո� */ 
	while (i < len)
		s[i++] = ' ';
		
	s[i] = '\0';
	
	reverse(s);
}

int main(void)
{
	int num, len;
	char s[100];
	
	while (1)
	{
		printf("Enter a integar, len: ");
		scanf("%d%d", &num, &len);
		
		itoa(num, s, len);
		printf("%d��%d�ֶο���ַ�����\n%s\n", num, len, s);		
	}

	return 0;
}

/*
Enter a integar, len: 13 5
13��5�ֶο���ַ�����
   13
Enter a integar, len: 13 3
13��3�ֶο���ַ�����
 13
Enter a integar, len: 13 2
13��2�ֶο���ַ�����
13

*/ 
