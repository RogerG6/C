# include <stdio.h>
int main(void)
{
	const int DN = 150;  //定义邓巴数（Dunbar's number） 
	int sum = 5;
	int n = 0;
	
	do
	{
		++n;
		sum = 2 * (sum - n);
		printf("第 %d 周Rabnud博士的朋友为 %d 个!\n", n, sum);
	}while (sum < DN);
	
	return 0;
}
