//2018年10月7日 13时56分
//英寸转换成厘米

# include <stdio.h>

int main(void)
{	
	float inch;
	
	printf("请输入英寸数：");
	scanf("%f", &inch);
	
	printf("%.2f 英寸 = %g 厘米\n", inch, 2.54*inch);  //.2表示输出的小数位为 2 位 
	
	return 0;
}

