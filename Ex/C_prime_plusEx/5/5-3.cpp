//2018��10��11�� 20ʱ22�� 
//������ת��������������
# include <stdio.h> 
int main(void) 
{
	int days, weeks, left;
	
	printf("Please enter days:");
	scanf("%d", &days);
	
	while (days > 0)
	{
		weeks = days / 7;
		left = days % 7;
		printf("%d days is %d weeks and %d days\n", days, weeks, left);
		
		printf("Please enter days:");
		scanf("%d", &days);
	}
	
	return 0;
}
