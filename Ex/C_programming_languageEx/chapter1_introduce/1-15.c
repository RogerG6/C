/* Date：2020/3/23
 * 1-15：重写1.2节中温度转换程序，使用函数实现温度转换计算
 */ 
 
#include <stdio.h> 
float fahr_to_cel(int fahr);	/* 函数原型声明 */
int main(void)
{
	float fahr;
	int lower = 0, upper = 300, step = 20;
	
	fahr = lower;
	printf("摄氏与华氏温度转换表\n");
	printf("------------------------------\n");
	printf("华氏	摄氏\n"); 
	while (fahr <= upper)
	{
		printf("%3.0f	%6.1f\n", fahr, fahr_to_cel(fahr));
		fahr += step;
	}
	return 0;
} 

float fahr_to_cel(int fahr) 
{
	return 5.0 / 9.0 * (fahr - 32);
}
