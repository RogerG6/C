//2018��10��20�� 12ʱ19��
//������ 
# include <stdio.h> 
# include <ctype.h>
# define LOWER 1
# define UPPER 1000 
int main(void)
{
	int guess;
	int n = 1;
	int lower = LOWER, upper = UPPER;
	char ch;
	
	printf("��������ѡ������"); 
	scanf("%d", &guess);
	while (!(guess >= LOWER && guess <= UPPER)) 
	{
		printf("��������ȷ�����ַ�Χ��");
	    scanf("%d", &guess);
	}
		
	
	printf("������Ҫ���ˣ�\n");
	printf("�����С�˾�����s������´��˾�����b, ����¶��˾�����y!\n");
	printf("����%d ��\n", n);
	
	
	while (1)
	{
		while(isspace(ch = getchar()) ) //�������пհ׷� 
			continue;
		if (ch == 'y')
		{
			printf("��¶���!\n");
			break;
		}
		if (ch == 's')
		{
			lower = n;
		}
		if (ch == 'b')
		{
			upper = n;
		}
		n = (lower + upper) / 2;
		printf("����%d ��\n", n);
	}
	
	return 0;
}
