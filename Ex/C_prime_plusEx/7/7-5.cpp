# include <stdio.h>
int main(void)
{
	int fp = 0;  //�����ţ�full point���ĸ��� 
	int ep = 0;  //�����̾�ţ� exclamatory point���ĸ��� 
	char c;
	
	while ((c = getchar()) != '#') 
	{
		switch (c)
		{
			case '.': putchar('!');
					  fp++;
					  break;
			case '!': putchar('!!');
					  ep++;
				      break;
			default : putchar(c);
					  break;
		}
	}
	printf("\nһ���滻�� %d �Σ�\n", fp + ep);
	
	return 0;
}
