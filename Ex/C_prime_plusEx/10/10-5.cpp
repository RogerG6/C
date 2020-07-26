# include <stdio.h>

double max_sub_min(double *, int );

int main(void)
{
	double arr[10] = {111, 5.2, 9.3, 7.8 , 5.4, 4.0, 4.5, 6.5, 1000.0, 100.0};
	
	printf("arr数组中最大值和最小值的差为：%.1lf\n", max_sub_min(arr, 10));
	return 0;
}

double max_sub_min(double * p, int n)   {

	double max, min;
	int i;
	 
	max = min = *p;
	for (i = 1; i < n; i++)
	{
		max > *(p + i) ? : max = *(p + i);
		min < *(p + i) ? : min = *(p + i);
	}	
	
	return max - min;
}
