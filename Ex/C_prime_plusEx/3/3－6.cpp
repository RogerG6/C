# include <stdio.h>
int main(void)
{
	double mw = 3.0e-23;  //mw为一个水分子的质量
	float quarts;
	
	scanf("%f", &quarts); 
	printf("一夸脱水有 %le 个水分子\n", 950 * quarts / mw);
	
	return 0; 
}
