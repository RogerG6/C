# include <stdio.h>

double mi(int a, int b)  //选出最小值 
{
	return a < b ? a : b;
}

int main(void)
{
	int min;
	
	min = mi(7, 9);
	printf("The minmum is %d\n", min);
	
	return 0;
}
