# include <stdio.h> 
void db_arr(int arr[][5], int n);
void show_arr(int arr[][5], int n);

int main(void)
{
	int a[3][5] = {{1, 2, 3, 5, 4}, {4, 5, 6, 7, 8}, {9, 8, 7, 6, 5}};
	
	show_arr(a, 3);
	db_arr(a, 3);
	show_arr(a, 3);
	
	return 0;
}

void db_arr(int arr[][5], int n)  //数组值变大两倍 
{
	int i, j;
	
	for (i = 0; i < n; i++)
		for (j = 0; j < 5; j++)
			arr[i][j] *= 2;
}

void show_arr(int arr[][5], int n)
{
	int i, j;
	
	for (i = 0; i < n; i++)
		for (j = 0; j < 5; j++)
			printf("%3d  ", arr[i][j]);
	printf("\n");
}


