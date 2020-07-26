# include <stdio.h>
int main(void)
{
	float tall;
	float inch = 2.54f;
	
	scanf("%f", &tall);
	printf("%f 厘米的身高为 %f 英寸\n", tall, inch * tall);
	
	return 0;
}
