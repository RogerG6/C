# include <stdio.h>
int main(void)
{
	int fp = 0;  //�����ţ�full point���ĸ��� 
	int ep = 0;  //�����̾�ţ� exclamatory point���ĸ��� 
	char c;
	
	while ((c = getchar()) != '#') 
	{
		if ('!' == c || '.' == c)
		{
			if('!' == c)
			{
				printf("!!");
			    ep++;
			}
			else
			{
				putchar('!');
				fp++;
			}
		}
		else
			putchar(c);
	}
	printf("\nһ���滻�� %d �Σ�\n", fp + ep);
	
	return 0;
}
