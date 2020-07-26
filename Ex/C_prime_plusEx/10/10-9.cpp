
//²»Ö§³ÖVLA 
# include <stdio.h>
void copy_arr(double ** t, int r, int c, double ar[r][c]);
void show_arr(int r, int c, double a[r][c]);

int main(void)
{
	int a = 3, b = 5;
	double source[3][5] = {{1.0, 2.0, 3.0, 4.0, 5.0}, {2.0, 4.0, 6.0, 8.0, 10.0}, {3.0, 5.0, 7.0, 9.0, 11.0}};
	double target[a][b];
	
	copy_arr(a, b, target, 3, 5, source);
	show_arr(a, b, target);
	
	return 0;
}

void copy_arr(double ** t, int r, int c, double ar[r][c])
{
	int i, j;
	for (i = 0; i < r; i++)
		for (j = 0; j < c; j++)
			t[i][j] = ar[i][j];
}

void show_arr(int r, int c, double a[r][c])
{
	int i, j ;
	
	for (i = 0; i < r; i++)
		for (j = 0; j < c; j++)	
			printf("%.1lf  ", a[i][j]);
	printf("\n");
}
