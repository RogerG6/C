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

/*��Dev��C++5.10�����н��Ϊ��
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Please enter your name: ����Ȩ
"����Ȩ"
"              ����Ȩ"
"����Ȩ              "
"      ����Ȩ"

--------------------------------
Process exited after 6.678 seconds with return value 0
�밴���������. . .


~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
