# include <stdio.h>
# define HAR(X, Y) (1/((1/(X) + 1/(Y))/2))
int main(void)
{
	float har;
	
	float x = 1;
	float y = 2;
	
	printf("x �� y �ĵ���ƽ����Ϊ%.2f\n", HAR(x, y));
	return 0;
}
