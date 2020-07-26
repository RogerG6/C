/* Date��2020/2/12
 * 3-3: ��д����expand(s1, s2)�����ַ���s1��������a-z֮����ټǷ������ַ���s2
 *		����չΪ�ȼ۵������б�abc...xyz��
 *		�ú������Դ����Сд��ĸ�����֣������Դ���a-b-c��a-z0-9��-a-z�����������
 *		��Ϊǰ����β���-�ַ�ԭ����ӡ 
 */ 

#include <stdio.h>
#include <ctype.h>

void expand(char s1[], char s2[])
{
	int i = 0, j = 0;
	char c;
	
	while ((c = s1[i++]) != '\0')
	{
		if (s1[i] == '-' && s1[i+1] >= c)
		{
			i++;
			while (c < s1[i])
				s2[j++] = c++;
		}
		else
			s2[j++] = c;
	}
	s2[j] = '\0';
}

int main(void)
{
	char s1[100], s2[100];
	int i;
	
	printf("Enter a string(a-z, 0-9): \ns1: ");
	gets(s1);
	expand(s1, s2);
	
	printf("s2: %s\n", s2);
	
	return 0;
}

/*
Enter a string(a-z, 0-9):
s1: --..a-g-a-b-d.a-c0-3-a-c---../
s2: --..abcdefg-abcd.abc0123-abc---../

--------------------------------
Process exited after 62.73 seconds with return value 0
�밴���������. . .


*/ 
