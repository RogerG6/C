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
	name ,fname, strlen(name), strlen(name), strlen(fname), strlen(fname)); //*����������������� 
	printf("%s %s\n%-*d %-*d",
	name ,fname, strlen(name), strlen(name), strlen(fname), strlen(fname));
	
	return 0;
	
}

/*��Dev��C++5.10�����н��Ϊ��
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Please enter your name:Melissa
Please enter your first name:Honeybee
Melissa Honeybee
      7        8
Melissa Honeybee
7       8
--------------------------------
Process exited after 8.253 seconds with return value 0
�밴���������. . .

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
