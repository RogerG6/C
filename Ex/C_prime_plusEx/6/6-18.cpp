# include <stdio.h>
int main(void)
{
	const int DN = 150;  //����˰�����Dunbar's number�� 
	int sum = 5;
	int n = 0;
	
	do
	{
		++n;
		sum = 2 * (sum - n);
		printf("�� %d ��Rabnud��ʿ������Ϊ %d ��!\n", n, sum);
	}while (sum < DN);
	
	return 0;
}
