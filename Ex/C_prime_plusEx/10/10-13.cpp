# include <stdio.h>

void read_arr(double a[][5], int n);
double avg(double * p, int n);
double t_avg(double a[][5], int n);
double max(double a[][5], int n);
void show_rlt(double a[][5], int n);

int main(void)
{
	double ar[3][5];
	
	read_arr(ar, 3);    //a
	show_rlt(ar, 3);   //e
	
	return 0;
}

void read_arr(double a[][5], int n)
{
	int i, j;
	
	for (i = 0; i < n; i++)
		for (j = 0; j < 5; j++)
		{
			scanf("%lf", &a[i][j]);
			getchar();     //ȥ������Ļس� 
		}
}

double avg(double * p, int n)
{
	int i;
	double tot = 0.0;
	
	for (i = 0; i < n; i++)
		tot += p[i];
	
	return tot / n;
}

double t_avg(double a[][5], int n)
{
	int i ;
	double tot = 0.0;
	
	for (i = 0; i < n; i++)
	{
		tot += 5 * avg(a[i], 5);
	}
	
	return tot/5/n;
}

double max(double a[][5], int n)
{
	int i, j;
	double max = a[0][0];
	
	for (i = 0; i < n; i++)
		for (j = 0; j < 5; j++)
		{
			if (max < a[i][j])
				max = a[i][j];
		}
	return max;
}

void show_rlt(double a[][5], int n)
{
	int i;
	for (i = 0; i < n; i++)   //b
		printf("��%d��ƽ��ֵΪ��%.1lf\n", i+1, avg(a[i], 5));
	printf("���������ƽ��ֵΪ��%.1lf\n", t_avg(a, n));  //c
	printf("�����е����ֵΪ��%.1lf\n", max(a, n));   //d

}
