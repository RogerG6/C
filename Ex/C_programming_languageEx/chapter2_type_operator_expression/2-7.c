/* Date：2020/2/11 
 * 2-7: 编写一个函数invert(x, p, n)，该函数返回对x执行下列操作后的结果值:
 * 		将x中从第p位开始的n个(二进制) 位求反(即：1变0，0变1) ，x的其余各位保持不变 
 */ 

#include <stdio.h>

/* 碾转相除法，以二进制打印整数 */ 
void show_bin(int n)
{
	if (n == 0) 
		return;
	else
	{
		show_bin(n/2);
		printf("%d", n%2);
	}
}

int invert(int x, int p, int n) 
{
	return x ^ (~(~0 << n) << (p-n+1));
}

int main(void)
{
	int x, p, n;
	int t;
	
	printf("请输入x, p, n: ");
	scanf("%d%d%d", &x, &p, &n);
	
	printf("invert前：%d	", x);	
	show_bin(x);
	putchar('\n');
	
	printf("invert后：%d	", t = invert(x,p, n));	
	show_bin(t);
	putchar('\n');

	return 0;
}

/*
请输入x, p, n: 215 6 7
invert前：215   11010111
invert后：168   10101000

--------------------------------
Process exited after 3.252 seconds with return value 0
请按任意键继续. . .

*/ 
