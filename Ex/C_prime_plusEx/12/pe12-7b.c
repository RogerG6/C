# include <stdio.h>
# include <stdlib.h>
# include <time.h>
# include "pe12-7a.c"
int main(void)
{
	int dice, side, roll, set, status;
	int i;
	
	srand((unsigned int )time(0));  //随机种子
	printf("Enter the number of sets; enter q to stop.\n") ;
	while (scanf("%d", &set) == 1)
	{
		printf("How many sides and how many dices?\n");
		while (status = scanf("%d%d", &side, &dice) != 2)   //个数和面数不对时重新输入 
		{
			printf("You should enter two integers.\n");
			printf("Let's begin again!\n");
			while (getchar() != '\n')
				continue;
			printf("How many sides and how many dices?\n") ;
			
			continue;
		}
		while (getchar() != '\n')   //跳过所有多余的输入 
				continue;
		printf("Here are %d sets of %d %d-sided throws.\n", set, dice, side);  //输出每次投掷的点数和 
		for (i = 0; i < set; i++)
		{
			printf("%d ", roll_n_dice(dice, side));
		}
		printf("\nHow many sets? Enter q to stop.\n");
	}
	
	
	return 0;
}
