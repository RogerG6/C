//2018��10��11�� 20ʱ11�� 
//������ת����Сʱ�ͷ��ӱ�ʾ  
# include <stdio.h>
int main (void)
{
	const int M_PER_H = 60;
	int min, hour, left;
	
	printf("Please enter your minutes: ");
	scanf("%d", &min);
	while(min > 0)
	{
		hour = min / M_PER_H;
		left = min % M_PER_H;
		printf("%d minutes is %d hours %d minutes!\n", min, hour, left);
		
		printf("Please enter your minutes: ");
		scanf("%d", &min);
	}
	
	return 0;
}
