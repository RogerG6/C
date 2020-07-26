/* Date��2020/3/16
 * 7-2����дһ�������Ժ���ķ�ʽ��ӡ�κ����롣�ó��������ܹ������û���ϰ���԰˽��ƻ�ʮ�����ƴ�ӡ��ͼ���ַ������ضϳ��ı���
 */
#include <stdio.h> 
#include <ctype.h>

#define MAXLEN 10
#define OCT		6

int inc(int pos, int n);

main(void)
{
	int c, pos;
	
	pos = 0;		//һ���е�λ�� 
	while ((c = getchar()) != EOF)
		if (iscntrl(c) || c == ' ')
		{			//non graphic char
			pos = inc(pos, OCT);
			printf(" \\%03o ", c); 
			
			if (c == '\n')
			{
				putchar('\n');
				pos = 0;
			}
		}
		else		//graphic char
		{
			pos = inc(pos, 1);
			putchar(c);
		}
	
	return 0;
}

int inc(int pos, int n)
{
	if (pos + n < MAXLEN)
		return pos + n;
	else
	{
		putchar('\n');
		return n;
	}
}

