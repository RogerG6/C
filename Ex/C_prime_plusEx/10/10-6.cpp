# include <stdio.h>

void sort_down(double *, int );
void show_arr(double *, int );

int main(void)
{
	double arr[10] = {1.0, 2.0, 3.0, 4.0 , 5.0, 6.0, 7.0, 8.0, 9.0, 10.0};
	
	sort_down(arr, 10);
	show_arr(arr, 10);
	
	return 0;
}

void sort_down(double * p, int n)   
{
	double temp;
	int i, j;
	 
	for (j = 0; j <= n - 2; j++)  //Ã°ÅÝÅÅÐò 
	{
		for (i = 0; i <= n-2-j; i++)
		{
			if (*(p + i) < *(p + i + 1))
			{
				temp = *(p + i);
				*(p + i) = *(p + i + 1);
				*(p + i + 1) = temp;
			}
		}	
	}
}

void show_arr(double * p, int n)
{
	int i ;
	
	for (i = 0; i < n; i++)
		printf("%.1lf  ", p[i]);
	printf("\n");
}
