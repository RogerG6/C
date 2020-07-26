//2018年10月20日21时51分
// 递归法求幂 
# include <stdio.h>

double pow_recursive(double base, double index);

int main(void)
{
	int i, j;
	while(scanf("%d%d", &i, &j) == 2)
		printf("%lf\n", pow_recursive(i, j));
	
	return 0;
}


double pow_recursive(double base, double index)
{
    if (index > 0)
    {
        index--;
        return (base * pow_recursive(base, index));
    }
    if (0 == index)
    {
        if (base == 0)
        {
            printf("The base number is 0 is not defined!\n");
        }
        return 1;
    }
    if (index < 0)
    {
    	if (base == 0)
    		return 0;
        index++;
        double tmp = 1 / base;
        return (tmp * pow_recursive(base, index));
    }
}
