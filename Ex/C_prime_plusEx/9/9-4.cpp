# include <stdio.h> 

double h_ave(double, double); //harmonic average ����ƽ���� 

int main(void)
{
	double i, j;
	
	printf("Enter two numbers:");
	scanf("%lf%lf", &i, &j);
	getchar();   //��������Ļس� 
	printf("The harmonic average of %lf and %lf is %lf\n",
							i, j, h_ave(i, j));
	return 0;
}

double h_ave(double a, double b)
{
	double m_num;
	
	m_num = (1/a + 1/b)/2;
	return 1/m_num;
}

