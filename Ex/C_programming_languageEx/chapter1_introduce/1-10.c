/* Date��2020/3/23
 * 1-10: ��дһ�������븴�Ƶ�����ĳ��򣬲������е��Ʊ���滻Ϊ\t���ѻ��˷��滻Ϊ\b���ѷ�б���滻Ϊ\\��
 *	     �������Խ��Ʊ���ͻ��˷��Կɼ��ķ�ʽ��ʾ����
 */ 


#include <stdio.h>
//#define NOTBLANK 'a'

int main(void)
{
	int c;//lastc = NOTBLANK;
	
	while ((c = getchar()) != EOF)
	{
		if (c == '\t')
			printf("\\t");
		else if (c == '\b')
			printf("\\b");
		else if (c == '\\')
			printf("\\\\");
		else
			putchar(c);
	}
	
	return 0;
}


/* �����
=================================
abcd    dkfj
abcd\tdkfj\t
ab\\df\df\f\f
ab\\\\df\\df\\f\\f
^Z

--------------------------------
====================================
 */ 
