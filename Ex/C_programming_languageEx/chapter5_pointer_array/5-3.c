/* Date��2020/3/7 
 * 5-3����ָ��ķ�ʽʵ�ֵ�2���еĺ���strcat������strcat(s, t)��tָ����ַ������Ƶ�sָ����ַ�����β��
 */ 

#include <stdio.h> 

void __strcat(char *s, char *t)
{
	while (*s)
		s++;
	while (*s++ = *t++)
		;
}

int main(void)
{
	char a[100] = "hello";
	char *b = "world!!!";
	
	__strcat(a, b);
	
	printf("String a: %s\n", a);
	
	return 0;
}


/*
String a: helloworld!!!

--------------------------------
Process exited after 0.3547 seconds with return value 0
�밴���������. . .


*/ 
