/* Date��2020/2/12
 * 3-1: �������й��۰���ҵ������У�whileѭ������ڹ�ִ����2�β��ԣ���ʵ
 * 		ֻҪһ�ξ��㹻(�����ǽ�����Ĳ�����ѭ����ִ��)����д�ú�����ʹ��
 *		��ѭ���ڲ�ִֻ��1�β��ԡ��Ƚ�2�ְ汾����������ʱ�� 
 */ 
 
#include <stdio.h>

int binsearch(int x, int a[], int n)
{
	int low = 0, high = n - 1, mid;
	
	mid = (low + high) / 2;
	while (low <= high && x != a[mid])
	{
		/* x < a[mid] */ 
		high = mid - 1;
		
		/* x > a[mid] */ 
		if (x > a[mid])
			low = mid + 1;
			
		mid = (low + high) / 2;
	}
	
	return low <= high ? mid : -1;
}

int main(void)
{
	int a[10] = {1, 2, 4, 8, 9, 10, 11, 14, 19, 20};
	int n;
	
	printf("Enter a num: ");
	scanf("%d", &n);
	
	printf("%sƥ���ֵ\n", binsearch(n, a, 10) == -1 ? "��" : "��"); 
	
	return 0;
}

/*
Enter a num: 12
��ƥ���ֵ

--------------------------------
Process exited after 2.912 seconds with return value 0
�밴���������. . .

*/ 
