# include <stdio.h>
int main(void)
{
	int i, j;
	char n, ch;
	
	printf("������һ����д��ĸ��");
	scanf("%c", &n); 
	
	for (i = 1; i <= n-'A'+1; i++)     //��ӡ������ 
	{
		for(j = 1; j <= n-'A'+1-i; j++)  //��ӡ��ĸǰ�Ŀո� 
		{
			printf(" ");
		}
		for (j = 1, ch = 'A'; j <= i; j++)  //��ӡ˳�����ĸ 
		{
			printf("%c", ch++);
		}
		ch -= 2;
		for(; j <= 2*i-1; j++)    //��ӡ�������ĸ 
		{
			printf("%c", ch--);
		}
		printf("\n");
	}   
	return 0;
}
