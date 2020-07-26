/* Date��2020/3/23 */ 
/* 1-8: ��дһ��ͳ�ƿո��Ʊ���ͻ��з������ĳ��� */ 

#include <stdio.h>

int main(void)
{
	int space = 0, tab = 0, enter = 0;
	int c;
	
	while ((c = getchar()) != EOF)
	{
		if (c == ' ')
			space++;
		else if (c == '\t')
			tab++;
		else if (c == '\n')
			enter++; 
	}
	
	printf("space = %d, tab = %d, enter = %d\n", space, tab, enter);
	
	return 0;
}

/* �����
==============================
abc
efg
hij jk
^Z
space = 1, tab = 1, enter = 3

==============================
�ܽ᣺
	��windowsƽ̨��EOF���룺��һ�еĿ�ͷ������ctrl + z 

-------------------------------- */ 
