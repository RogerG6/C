# include <stdio.h>
int main(void)
{
	int inr;  //�������� 
	int n_even = 0;   //����ż���ĸ��� 
	float s_even = 0;   //ż������� 
	int n_odd = 0;    //�����ĸ��� 
	float s_odd = 0;    //��������� 
	
	scanf("%d", &inr);
	while (inr != 0)
	{
		if (inr % 2 == 0)
		{
			n_even++;
			s_even += inr;
		}
		else 
		{
			n_odd++;
			s_odd += inr;
		}
		scanf("%d", &inr);
	}
	
	printf("The number of evennumber is %d, average of them is %f\n", n_even, s_even/n_even);
	printf("The number of oddnumber is %d, average of them is %f\n", n_odd, s_odd/n_odd);
	
	return 0;	
}
