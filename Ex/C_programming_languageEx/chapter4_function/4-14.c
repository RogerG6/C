/* Date：2020/3/7 
 * 4-14：定义宏swap(t, x, y)以交换t类型的两个参数。(使用程序块结构会对你有所帮助)
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
