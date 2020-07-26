# include <stdio.h>
# define TYPE1 17850
# define TYPE2 23900
# define TYPE3 29750
# define TYPE4 14875
# define RATE1 0.15
# define RATE2 0.28

int main(void)
{
	int choice, type;
	float tax, income;
	
	while (1)
	{
		printf("-----------------------------------------------------------\n");
		printf("(1) 单身                     （2）户主\n");
		printf("(3) 已婚， 共有              （4）已婚， 离异\n");
		printf("-----------------------------------------------------------\n");
		printf("Please enter your choice:");
		
		do 
		{
			scanf("%d", &choice);
			switch (choice)
			{
				case 1: type = TYPE1;
						break;
				case 2: type = TYPE2;
						break;
				case 3: type = TYPE3;
						break;
				case 4: type = TYPE4;
						break;
				default: printf("Please enter your choice:");
			}
		}while (choice < 1 || choice > 4);
		
		printf("Please enter your income: ");
		scanf("%f", &income);
		
		if (income <= type)
			tax = income * RATE1;
		else 
			tax = type * RATE1 + (income - type) * RATE2;
			
		printf("The tax you must pay is : %f\n", tax);
	}
	
	return 0;
}
