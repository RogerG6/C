# include <stdio.h>
int main(void) 
{
	int ch;
	int A = 0, a = 0;
	
	while ((ch = getchar()) != EOF)
	{
		if (ch >= 65 && ch <= 90)
			A++;
		if (ch >= 97 && ch <= 122)
			a++;
	}
	printf("��д��ĸ��%d����Сд��ĸ��%d��\n", A, a);
	
	return 0;
}
