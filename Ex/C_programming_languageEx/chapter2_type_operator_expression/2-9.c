/* Date：2020/2/11 
 * 2-9: 在求对二的补码时，表达式x &= (x-1)可以删除x中最右边的值为1的一个二进制位。
 *		请解释这样做的道理。用这一方法重写bitcount函数，以加快执行速度
 *		ps: bitcount函数：统计x中值为1的位数 
 *
 *		eg.
 *			1111
 *			1110
 *			1100
 *			1000
 *			0000
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


int bitcount(unsigned int x)
{
	unsigned int cnt = 0;
	
	for (; x != 0; x &= x - 1)
		cnt++;	
	return cnt;
}

int main(void)
{
	unsigned int num;
	
	printf("请输入num: ");
	scanf("%d", &num);
	
	printf("%d	", num);
	show_bin(num);
	printf(" 中有%d个 1 \n", bitcount(num));
	
	return 0;
}

/*
请输入num: 215
215     11010111 中有6个 1

--------------------------------
Process exited after 0.9657 seconds with return value 0
请按任意键继续. . .

*/ 
