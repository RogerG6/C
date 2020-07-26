/* Date：2020/2/11 
 * 2-6: 编写一个函数setbits(x, p, n, y)，该函数返回对x执行下列操作后的结果
 *		值：将x中从第p位开始的n个(二进制) 位设置为y中最右边n位的值，x的其余各位保持不变 
 */ 
 
#include <stdio.h>

/* 移位方法，以二进制打印整数 */ 
void show_bin(int n)
{
	if (n == 0) 
		return;
	else
	{
		show_bin(n>>1);
		printf("%d", n&1);
	}
}

int setbits(int x, int p, int n, int y)
{
	return x & ~(~(~0 << n) << (p-n+1)) | (y & ~(~0 << n)) << (p-n+1);
}

int main(void)
{
	int x, y, p, n;
	int t;
	
	printf("请输入x, p, n, y: ");
	scanf("%d%d%d%d", &x, &p, &n, &y);
	
	printf("setbits前：%d	", x);	
	show_bin(x);
	putchar('\n');
	
	printf("setbits后：%d	", t = setbits(x,p, n, y));	
	show_bin(t);
	putchar('\n');
	
	return 0;
}

/*
请输入x, p, n, y: 128 5 4 10
setbits前：128  10000000
setbits后：168  10101000

--------------------------------
Process exited after 72.28 seconds with return value 0
请按任意键继续. . .

*/ 
