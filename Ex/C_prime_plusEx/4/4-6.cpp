# include <stdio.h> 
# include <string.h>
int main(void)
{
	char name[10], fname[10];
	
	printf("Please enter your name:");
	scanf("%s", name);
	printf("Please enter your first name:");
	scanf("%s", fname);
	
	printf("%s %s\n%*d %*d\n",
	name ,fname, strlen(name), strlen(name), strlen(fname), strlen(fname)); //*用来描述后面的数据 
	printf("%s %s\n%-*d %-*d",
	name ,fname, strlen(name), strlen(name), strlen(fname), strlen(fname));
	
	return 0;
	
}

/*在Dev－C++5.10中运行结果为：
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Please enter your name:Melissa
Please enter your first name:Honeybee
Melissa Honeybee
      7        8
Melissa Honeybee
7       8
--------------------------------
Process exited after 8.253 seconds with return value 0
请按任意键继续. . .

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
