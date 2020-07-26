/* Date��2020/2/13
 * 3-4: �����ĶԶ������ʾ�У����Ǳ�д��itoa�������ܴ������ĸ�������n����-(2^�ֳ�-1)�����
 *		�����ԭ���޸ĸú�����ʹ�����κλ���������ʱ���ܴ�ӡ����ȷ��ֵ 
 *
 *		��charΪ�� 
 *		��Ϊ��n =  -(2^7-1)ʱ������ͨ��n = -n�� -128ת����128����Ϊchar_max = 127 
 */ 
 
#include <stdio.h>
#include <string.h>

#define abs(x) ((x >= 0) ? (x) : (-x))

void reverse(char s[])
{
	int i, j, t;
	
	for (i = 0, j = strlen(s) - 1; i < j; i++, j--)
	{
		t = s[i];
		s[i] = s[j];
		s[j] = t;
	}
}

/* �Ľ���itoa */ 
void myitoa(char n, char s[])
{
	int i = 0, sign;

	sign = n;
	
	do
	{
		s[i++] = abs(n % 10) + '0';
	}while ((n /= 10) != 0);
	
	if (sign < 0)
		s[i++] = '-';

	s[i] = '\0';
	
	reverse(s);
}

/*����֮ǰ��д��itoa*/ 
void itoa(char n, char s[])
{
	int i = 0, sign;

	if ((sign = n) < 0)
		n = -n;

	do
	{
		s[i++] = n % 10 + '0';
	}while ((n /= 10) > 0);
	
	if (sign < 0)
		s[i++] = '-';

	s[i] = '\0';
	
	reverse(s);	
}

/* ��λ�������Զ����ƴ�ӡ���� */ 
void show_bin(int n, int bits)
{
	if (bits == 0) 
	{
		return;
	}
	else
	{
		show_bin(n>>1, --bits);
		printf("%d", n&1);
	}
}

int main(void)
{
	char s[100];
	char num;
#if 0	
	while (1)
	{
		scanf("%d", &num);
		show_bin(num, 8*sizeof(num));
		putchar('\n');
	}
#endif
	
	printf("Enter an integar��");
	scanf("%d", &num);

	itoa(num, s);
	printf("itoa  : %d(integar) = %s(string)\n", num, s);
	
	myitoa(num, s);
	printf("myitoa: %d(integar) = %s(string)\n", num, s);
	
	return 0;
}

/*
Enter an integar��-128
itoa  : -128(integar) = -((string)
myitoa: -128(integar) = -128(string)

--------------------------------
Process exited after 3.09 seconds with return value 0
�밴���������. . .*/ 
