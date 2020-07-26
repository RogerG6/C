//2018年10月11日 20时29分 
//厘米转换成英寸 
# include <stdio.h> 
# define FT_TO_CM 30.48
int main(void)
{
	float tall,left;
	int feet;
	
	printf("Enter a height in centimeters:");
	scanf("%f", &tall);
	
	while(tall > 0)
	{
		feet = (int)(tall/(float)FT_TO_CM);  // 除号两边最好同种类型 
		left = (tall/(float)FT_TO_CM - feet) * 12;
		
		printf("%0.1f cm = %d feet, %0.1f inches\n", tall, feet, left);
		printf("Enter a height in centimeters(<=0 to quit):");
		scanf("%f", &tall);
	}
	printf("bye");
	return 0;
}

/*在Dev－C++5.10中运行结果为：
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Enter a height in centimeters:182
182.0 cm = 5 feet, 11.7 inches
Enter a height in centimeters(<=0 to quit):168.7
168.7 cm = 5 feet, 6.4 inches
Enter a height in centimeters(<=0 to quit):0
bye
--------------------------------
Process exited after 15.53 seconds with return value 0
请按任意键继续. . .
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
