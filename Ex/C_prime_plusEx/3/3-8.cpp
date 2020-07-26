# include <stdio.h>
int main(void)
{
	float cup;  //因为杯数可能为小数 
	
	scanf("%f", &cup);
	printf("%f 杯 = %f 品脱\n", cup, cup / 2);
	printf("%f 杯 = %f 盎司\n", cup, cup * 8);
	printf("%f 杯 = %f 大汤勺\n", cup, cup * 8 * 2);
	printf("%f 杯 = %f 茶勺\n", cup, cup * 8 * 2 * 3);
	
	return 0; 
	
}
