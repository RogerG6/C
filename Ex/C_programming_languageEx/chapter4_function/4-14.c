/* Date��2020/3/7 
 * 4-14�������swap(t, x, y)�Խ���t���͵�����������(ʹ�ó����ṹ�������������)
 */ 
 
#include <stdio.h>

#define swap(t, x, y) { t _z; _z = x; x = y; y = _z; }

int main(void)
{
	int a = 10, b = 20;
	
	swap(int, a, b);
	printf("a = %d, b = %d\n", a, b);
	
	return 0;
}
