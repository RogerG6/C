# include <stdio.h>
int main(void)
{
	int inr;  //定义整数 
	int n_even = 0;   //定义偶数的个数 
	float s_even = 0;   //偶数的求和 
	int n_odd = 0;    //奇数的个数 
	float s_odd = 0;    //奇数的求和 
	
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
