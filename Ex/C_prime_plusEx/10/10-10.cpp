# include <stdio.h>

void add_to_arr(int * t, int * a, int * b, int n);
void show_arr(int * p, int n);

int main(void) 
{
	int arr1[4] = {2, 4, 5, 8};
	int arr2[4] = {1, 0, 4, 6};
	int arr3[4];
	
	add_to_arr(arr3, arr1, arr2, 4);
	show_arr(arr3, 4);
	
	return 0;
}

//两个数组各元素相加，赋给另一个数组 
void add_to_arr(int * t, int * a, int * b, int n) 
{
	int i;
	
	for (i = 0; i < n; i++)
		t[i] = a[i] + b[i];
}

void show_arr(int * p, int n)
{
	int i;
	
	for (i = 0; i < n; i++)	
		printf("%d  ", p[i]);
	printf("\n");
}
