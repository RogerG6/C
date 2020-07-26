# include <stdio.h>

int arr_max(int *, int );

int main(void)
{
	int arr[10] = {1, 5, 9, 78 , 54, 4, 45, 6, 100, 10};
	
	printf("The max in arr is %d\n", arr_max(arr, 10));
	return 0;
}

int arr_max(int * p, int n)   // 求数组中最大值 
{
	int max;
	int i;
	
	max = *p;
	for (i = 1; i < n; i++)
		max > *(p + i) ? : max = *(p + i);
	
	return max;
}
