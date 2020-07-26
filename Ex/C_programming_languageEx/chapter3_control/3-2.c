/* Date��2020/2/12
 * 3-2: ��дһ������escape(s, t)�����ַ���t���Ƶ��ַ���s�У����ڸ��ƹ����н�
 *		���з����Ʊ���Ȳ��ɼ��ַ��ֱ�ת��Ϊ\n, \t����Ӧ�Ŀɼ���ת���ַ�����
 *		Ҫ��ʹ��switch���
 *		�ٱ�дһ�������෴���ܵĺ������ڸ��ƹ����н�ת���ַ�����ת��Ϊʵ���ַ� 
 */ 
#include <stdio.h> 

/* t cpy to s, ʵ���ַ�ת����\n \t */
void escape(char s[], char t[])
{
	int i, j;
	for (i = j = 0; t[i] != '\0'; i++)
	{
		switch(t[i])
		{
			case '\n': 
				s[j++] = '\\';
				s[j++] = 'n';
				break;
			case '\t': 
				s[j++] = '\\';
				s[j++] = 't';
				break;
				
			default  : 
				s[j++] = t[i];
				break;
		}
	}
	s[j] = '\0';
}

/* s cpy to t, \n \tת����ʵ���ַ� */ 
void diescape(char s[], char t[])
{
	int i, j;
	
	for (i = j = 0; s[i] != '\0'; i++)
	{
		switch (s[i])
		{
			case '\\':
				if (s[i+1] == 'n')
				{
					t[j++] = '\n';
					i++;					
				}
				else if (s[i+1] == 't')
				{
					t[j++] = '\t';
					i++;					
				}
				else
					t[j++] = s[i];
				
				break;
			default  :
				t[j++] = s[i];
				break;
		}
	}
	t[j] = '\0';
}

int main(void)
{
	char s[100], t[100], c;
	int i = 0;
	
	printf("Enter a string: ");
	//gets(t);
	while ((c = getchar()) != EOF)
		t[i++] = c;
	t[i] = '\0';
	
	escape(s, t);
	printf("After escape: \ns: %s\nt: %s\n", s, t);
	
	diescape(s, t);
	printf("After diescape: \ns: %s\nt: %s\n", s, t);
		
	return 0;
}

/*
Enter a string: a
b       c
d
^Z
After escape:
s: a\nb\tc\nd\n
t: a
b       c
d

After diescape:
s: a\nb\tc\nd\n
t: a
b       c
d


--------------------------------
Process exited after 7.121 seconds with return value 0
�밴���������. . .

*/ 

