/* Date��2020/3/20
 * 7-9: ������isupper�����ĺ�������ͨ��ĳ�ַ�ʽʵ���Դﵽ��ʡ�ռ��ʱ���Ŀ�ġ�
 *	    ���ǽ�ʡ�ռ��ʱ��ķ�ʽ��
 */ 
#include <stdio.h>

#define isupper(c) ((c >= 'A' && c <= 'Z') ? (1) : (0))

main(void)
{
	char ua = 'A', a = 'a';
	
	printf("%c is %s\n%c is %s\n", ua, isupper(ua) ? "upper" : "lower", 
				a, isupper(a) ? "upper" : "lower");
	return 0;
}
