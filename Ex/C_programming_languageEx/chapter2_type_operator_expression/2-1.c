/* Date��2020/2/12 
 * 2-1: ��дһ��������ȷ���ֱ���signed��unsigned�޶���char, short, int��long���ͱ���
 *		��ȡֵ��Χ��
 *		����1����ӡ��׼ͷ�ļ�����Ӧ��ֵ <limits.h>
 *		����2��ֱ�Ӽ��㷽ʽʵ��
 *
 *		������Ҫʵ�ַ���2 
 */ 
 
#include <stdio.h> 

int main(void)
{
	printf("signed char : %d ~ %d\n", -(char)((unsigned char)~0 >> 1), (char)((unsigned char)~0 >> 1));
	printf("signed short: %d ~ %d\n", -(short)((unsigned short)~0 >> 1), (short)((unsigned short)~0 >> 1));	
	printf("signed int  : %d ~ %d\n", -(int)((unsigned int)~0 >> 1), (int)((unsigned int)~0 >> 1));	
	printf("signed long : %ld ~ %ld\n", -(long)((unsigned long)~0 >> 1), (long)((unsigned long)~0 >> 1));
	
	printf("unsigned char : %u ~ %u\n", 0, (unsigned char)~0);
	printf("unsigned short: %u ~ %u\n", 0, (unsigned short)~0);
	printf("unsigned int  : %u ~ %u\n", 0, (unsigned int)~0);
	printf("unsigned long : %lu ~ %lu\n", 0, (unsigned long)~0);
	
	return 0;
}

/*
signed char : -127 ~ 127
signed short: -32767 ~ 32767
signed int  : -2147483647 ~ 2147483647
signed long : -2147483647 ~ 2147483647
unsigned char : 0 ~ 255
unsigned short: 0 ~ 65535
unsigned int  : 0 ~ 4294967295
unsigned long : 0 ~ 4294967295

--------------------------------
Process exited after 2.235 seconds with return value 0
�밴���������. . .


*/ 
