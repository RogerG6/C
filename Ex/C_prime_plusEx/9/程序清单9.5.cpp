# include <stdio.h>
int imax(int, int);
int main(void)
{
	printf("%d �� %d �����ֵΪ��%d\n", 3, 5, imax(3, 5));
	printf("%d �� %d �����ֵΪ��%d\n", 3, 5, imax(3.0, 5.0));
	
	return 0;
}

int imax(int n, int m)
{
	return (n > m ? n : m);
}
