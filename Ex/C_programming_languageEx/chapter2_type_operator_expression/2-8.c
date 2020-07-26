/* Date：2020/2/11 
 * 2-8: 编写一个函数rightrot(x, n)，该函数返回将x循环右移(即从最右端移出的位将从最左端移入) n(二进制)位后
 *		所得到的值。 
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

unsigned char rightrot(unsigned char x, int n)
{
	int bit;
	int bits = 8*sizeof(x);
	int i;
	
	for (i = 1; i <= n; i++)
	{
		bit = x & 1;
		x >>= 1;
		x |= bit << (bits-1);
	//	printf("bit = %d, bits = %d\n", bit, bits);
	}
	
	return x;
}

int main(void)
{
	unsigned char x;
	int n;
	unsigned char t;
	
	printf("请输入x, n: ");
	scanf("%d%d", &x, &n);
	
	printf("rightrot前：%d	", x);	
	show_bin(x);
	putchar('\n');
	
	printf("rightrot后：%d	", t = rightrot(x, n));	
	show_bin(t);
	putchar('\n');

	return 0;
}

/*
请输入x, n: 215 5
rightrot前：215 11010111
rightrot后：190 10111110

--------------------------------
Process exited after 3.351 seconds with return value 0
请按任意键继续. . .

*/ 

