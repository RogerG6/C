# include <stdio.h>
# include <float.h>

int main(void)
{
	float f = 1.0/3.0;
	double d = 1.0/3.0;
	
	printf("%0.3f  %0.6f  %0.12f\n", f, f, f);
	printf("%0.3Lf  %0.6Lf  %0.12lf\n", d, d, d);
	printf("%d  %d\n", FLT_DIG, DBL_DIG);
	
	return 0;
}
