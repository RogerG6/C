# include <stdio.h>

void jolly();   //前置声明时，形参可以省略，但返回类型不可省 
void deny();

int main (void)
{
	jolly()	;
	jolly();
	jolly();
	deny();
	
	return 0;
}

void jolly(void)
{
	printf("For he's a jolly good fellow!\n");
}

void deny(void)
{
	printf("Which nobody can deny!\n");
}
