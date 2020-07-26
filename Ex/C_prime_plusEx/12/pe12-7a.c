# include <stdio.h>
# include <stdlib.h>

static int rollem(int side)
{
	int roll;
	
	roll = rand() % side + 1;
	
	return roll;
}

int roll_n_dice(int dice, int side)
{
	int d;
	int total = 0;
	
	if (side < 2) 
	{
		printf("Need at least 2 sides.\n");
		return -2;
	}
	if (dice < 1)
	{
		printf("Need at least 1 dice.\n");
		return -1;
	}
	for (d = 0; d < dice; d++)
		total += rollem(side);
	return total;
}

