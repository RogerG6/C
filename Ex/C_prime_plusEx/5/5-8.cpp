# include <stdio.h>
int main(void)
{
	int ft;
	int se;
	
	printf("This program computes moduli.\n");
	printf("Enter an integer to serve as the second operand:");
	scanf("%d", &se);
	printf("Now enter the first operand:");
	scanf("%d", &ft);
	while (ft > 0)
	{
		printf("%d %% %d is %d\n", ft, se, ft % se);
		printf("Now enter the first operand(<= 0 to quit):");
		scanf("%d", &ft);
	}
	printf("Done\n");
	
	return 0;
}
