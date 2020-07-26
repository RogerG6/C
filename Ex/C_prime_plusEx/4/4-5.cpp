# include <stdio.h>
int main(void)
{
	float speed, size;
	
	printf("Please enter your downloadspeed(Mb) and size(MB) of file : ");
	scanf("%f %f", &speed, &size);
	printf("At %0.2f megabits per second, a file of %0.2f megabytes\n\
downloads in %0.2f seconds.", speed, size, 8*size/speed);
	
	return 0;
}

/*在Dev－C++5.10中运行结果为：
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Please enter your downloadspeed(Mb) and size(MB) of file : 18.12 2.2
At 18.12 megabits per second, a file of 2.20 megabytes
downloads in 0.97 seconds.
--------------------------------
Process exited after 8.789 seconds with return value 0
请按任意键继续. . .

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
