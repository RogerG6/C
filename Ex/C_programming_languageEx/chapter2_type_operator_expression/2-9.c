/* Date��2020/2/11 
 * 2-9: ����Զ��Ĳ���ʱ�����ʽx &= (x-1)����ɾ��x�����ұߵ�ֵΪ1��һ��������λ��
 *		������������ĵ�������һ������дbitcount�������Լӿ�ִ���ٶ�
 *		ps: bitcount������ͳ��x��ֵΪ1��λ�� 
 *
 *		eg.
 *			1111
 *			1110
 *			1100
 *			1000
 *			0000
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
	
	printf("������num: ");
	scanf("%d", &num);
	
	printf("%d	", num);
	show_bin(num);
	printf(" ����%d�� 1 \n", bitcount(num));
	
	return 0;
}

/*
������num: 215
215     11010111 ����6�� 1

--------------------------------
Process exited after 0.9657 seconds with return value 0
�밴���������. . .

*/ 
