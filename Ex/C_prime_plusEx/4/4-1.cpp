# include <stdio.h>
int main(void)
{
//	char a[10];
	
	char fname[40];
char lname[40];
printf("Enter your first name: ");
scanf("%s", fname);
printf("Enter your last name: ");
scanf("%s", lname);
printf("%s, %s\n", lname, fname);
	
	return 0;
}


/*��Dev��C++5.10�����н��Ϊ��
~~~~~~~~~~~~~~~~~~~~~~~
Please enter your name:������Ȩ
������Ȩ

--------------------------------
Process exited after 19.83 seconds with return value 0
�밴���������. . .
~~~~~~~~~~~~~~~~~~~~~~~~~*/
