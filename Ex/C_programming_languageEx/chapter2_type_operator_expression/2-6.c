/* Date��2020/2/11 
 * 2-6: ��дһ������setbits(x, p, n, y)���ú������ض�xִ�����в�����Ľ��
 *		ֵ����x�дӵ�pλ��ʼ��n��(������) λ����Ϊy�����ұ�nλ��ֵ��x�������λ���ֲ��� 
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

int setbits(int x, int p, int n, int y)
{
	return x & ~(~(~0 << n) << (p-n+1)) | (y & ~(~0 << n)) << (p-n+1);
}

int main(void)
{
	int x, y, p, n;
	int t;
	
	printf("������x, p, n, y: ");
	scanf("%d%d%d%d", &x, &p, &n, &y);
	
	printf("setbitsǰ��%d	", x);	
	show_bin(x);
	putchar('\n');
	
	printf("setbits��%d	", t = setbits(x,p, n, y));	
	show_bin(t);
	putchar('\n');
	
	return 0;
}

/*
������x, p, n, y: 128 5 4 10
setbitsǰ��128  10000000
setbits��168  10101000

--------------------------------
Process exited after 72.28 seconds with return value 0
�밴���������. . .

*/ 
