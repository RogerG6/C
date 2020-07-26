/* Date��2020/2/11 
 * 2-7: ��дһ������invert(x, p, n)���ú������ض�xִ�����в�����Ľ��ֵ:
 * 		��x�дӵ�pλ��ʼ��n��(������) λ��(����1��0��0��1) ��x�������λ���ֲ��� 
 */ 

#include <stdio.h>

/* ��ת��������Զ����ƴ�ӡ���� */ 
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
	
	printf("������x, p, n: ");
	scanf("%d%d%d", &x, &p, &n);
	
	printf("invertǰ��%d	", x);	
	show_bin(x);
	putchar('\n');
	
	printf("invert��%d	", t = invert(x,p, n));	
	show_bin(t);
	putchar('\n');

	return 0;
}

/*
������x, p, n: 215 6 7
invertǰ��215   11010111
invert��168   10101000

--------------------------------
Process exited after 3.252 seconds with return value 0
�밴���������. . .

*/ 
