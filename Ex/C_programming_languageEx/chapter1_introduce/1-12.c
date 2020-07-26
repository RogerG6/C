/* Date��2020/3/23
 * 1-12: ��дһ��������ÿ��һ�����ʵ���ʽ��ӡ����
 */ 
#include <stdio.h>
#define IN 1
#define OUT 0
 
int main(void)
{
	int c, lastc;
	int state = OUT;
	
	lastc = ' ';
	while ((c = getchar()) != EOF)
		if (c == ' ' || c == '\t' || c == '\n') {
			if (state == IN){
				putchar('\n');
				state = OUT;
			}
		}	
		else if (state == OUT){
			state = IN;
			putchar(c);
		}else
			putchar(c);
	
	return 0;
}

/* �����
�������������������������������������������������������� 
  so you are   a  b o y !
so
you
are
a
b
o
y
!
^Z

-------------------------------- 
��������������������������������������������������������
*/ 
