# include <stdio.h>

void copy_arr(double * t1, const double * s, int n);  //最好使用const，防止改变源数组 
void show_arr(const double * p, int n);

int main(void)
{
	double a[7] = {1.3, 5.1, 5.0, 4.0, 6.0, 8.0 , 90.0};
	double b[3];
	
	copy_arr(b, a + 2, 3);
	show_arr(b, 3);
	
	return 0;
}

void copy_arr(double * t1, const double * s, int n)
{
	int i;
	for (i = 0; i < n; i++)
		*(t1 + i) = *(s + i);
}

void show_arr(const double * p, int n)
{
	int i;
	for (i = 0; i < n; i++) 
		printf("%.1lf  ", *(p + i));
	printf("\n");
}
