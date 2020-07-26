/* Date：2020/3/20
 * 7-9: 类似于isupper这样的函数可以通过某种方式实现以达到节省空间或时间的目的。
 *	    考虑节省空间或时间的方式。
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
