/* Date：2020/3/23
 * 1-2：做个实验，当printf函数的参数字符串中包含\c(其中c是上面的转义字符序列中未曾列出的某一个字符)
 *	    时，观察一下会出现什么情况
 */


#include <stdio.h> 

int main(void)
{
	printf("hello world\c");	/* 加入\c会产生编译警告 */
	return 0;
}


/* 输出结果为
 * hello worldc
	--------------------------------
	Process exited after 0.3726 seconds with return value 0
	请按任意键继续. . .
 */ 
 


