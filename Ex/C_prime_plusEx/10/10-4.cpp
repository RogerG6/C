# include <stdio.h>

int max_xb(double *, int );

int main(void)
{
	double arr[10] = {111, 5.2, 9.3, 7.8 , 5.4, 4.0, 4.5, 6.5, 1000.0, 190.0};
	
	printf("arr���������ֵ���±�Ϊ��%d\n", max_xb(arr, 10));
	return 0;
}

int max_xb(double * p, int n)   // �����������ֵ���±� 
{
	double max;
	int i;
	int xiabiao = 0;
	 
	max = *p;
	for (i = 1; i < n; i++)
	{
		max > *(p + i) ? : (max = *(p+i), xiabiao = i);
	//	printf("%d ", xiabiao);
	}	
	
	return xiabiao;
}
