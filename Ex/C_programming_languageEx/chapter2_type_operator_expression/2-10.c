/* Date��2020/2/11 
 * 2-10: ���±�д����д��ĸת����Сд��ĸ�ĺ���lower�������������ʽ������е�if else�ṹ 
 */ 
#include <stdio.h>

int lower(int c)
{
	return (c >= 'A' && c <= 'Z' ? c-'A'+'a' : c);
}

int main(void)
{
	char str[100] = "HELLOWORld";
	int i;
	
	for (i = 0; str[i] != '\0'; i++) 
	{
		str[i] = lower(str[i]);
	}
	
	printf("string: %s\n", str);
	
	return 0;
}

/*
string: helloworld

--------------------------------
Process exited after 0.1911 seconds with return value 0
�밴���������. . .

*/ 
