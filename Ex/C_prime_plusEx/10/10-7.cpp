# include <stdio.h>
void copy_arr(double t[][3], double s[][3], int r );
void show_arr(double a[][3], int n);

int main(void)
{
	double a[2][3] = {{1, 2, 3}, {9, 6, 3}};
	double b[2][3];
	
	copy_arr(b, a, 2);
	show_arr(b, 2);
	printf("\n");
	
	return 0;
}

void copy_arr(double t[][3], double s[][3], int r )
{
	int i, j;
	for (i = 0; i < r; i++)
		for (j = 0; j < 3; j++)
			t[i][j] = s[i][j];
}

void show_arr(double a[][3], int n)
{
	int i, j;
	for (i = 0; i < n; i++)
		for (j = 0; j < 3; j++)
			printf("%.1lf  ", a[i][j]);
}
