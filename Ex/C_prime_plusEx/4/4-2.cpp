# include <stdio.h>
int main(void)
{
	char a[30];
	
	printf("Please enter your name:");
	scanf("%s", a);
	
	printf("\"%s\"\n", a);
	printf("\"%20s\"\n", a);
	printf("\"%-20s\"\n", a);
	printf("\"%12s\"\n", a);
	
	return 0;
}

/*在Dev－C++5.10中运行结果为：
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Please enter your name: 郭良权
"郭良权"
"              郭良权"
"郭良权              "
"      郭良权"

--------------------------------
Process exited after 6.678 seconds with return value 0
请按任意键继续. . .


~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
