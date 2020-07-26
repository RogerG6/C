# include <stdio.h>
int main(void)
{
	float f;

		scanf("%f", &f);
		printf("The input is %0.1f or %0.1e.\n", f, f);
		printf("The input is %+0.3f or %0.3e.\n", f, f);
	
	return 0;	
}

/*
在Dev－C++5.10中运行结果为：
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
21.290
The input is 21.3 or 2.1e+001.
The input is +21.290 or 2.129e+001.

--------------------------------
Process exited after 3.761 seconds with return value 0
请按任意键继续. . .

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
