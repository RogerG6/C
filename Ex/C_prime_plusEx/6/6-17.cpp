# include <stdio.h>
int main(void)
{
	const float r = 0.08;
	int year = 0;
	float sum = 1000000;
	
	do
	{
		sum = sum * (1 + r)	;
		sum = sum -100000;
		year++;
	}while(sum > 0);
	
	printf("After %d years, Chuckie' account will be empty\n", year);
	
	return 0;
}
