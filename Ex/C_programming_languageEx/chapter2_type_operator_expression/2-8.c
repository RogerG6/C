/* Date��2020/2/11 
 * 2-8: ��дһ������rightrot(x, n)���ú������ؽ�xѭ������(�������Ҷ��Ƴ���λ�������������) n(������)λ��
 *		���õ���ֵ�� 
 */ 
#include <stdio.h>

/* ��λ�������Զ����ƴ�ӡ���� */ 
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
	
	printf("������x, n: ");
	scanf("%d%d", &x, &n);
	
	printf("rightrotǰ��%d	", x);	
	show_bin(x);
	putchar('\n');
	
	printf("rightrot��%d	", t = rightrot(x, n));	
	show_bin(t);
	putchar('\n');

	return 0;
}

/*
������x, n: 215 5
rightrotǰ��215 11010111
rightrot��190 10111110

--------------------------------
Process exited after 3.351 seconds with return value 0
�밴���������. . .

*/ 

