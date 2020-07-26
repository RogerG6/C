# include <stdio.h>
# define CHOICE1 8.75
# define CHOICE2 9.33
# define CHOICE3 10.00
# define CHOICE4 11.20
# define CHOICE5 "quit"
# define RATE1 0.15
# define RATE2 0.2
# define RATE3 0.25
# define OT 40
# define OTTR 1.5
# define S_WT 400
# define BREAK1 300
# define BREAK2 450
# define TAX1 BREAK1 * RATE1
# define TAX2 TAX1 + (BREAK2-BREAK1) * RATE2

int main(void)
{
	int choice;
//	int i = 1;
	float s_ph = 10;
	int hour;
	float salary, tax, ni;  //ni 为 net income
	
	printf("***************************************************************\n");
	printf("Enter the number corresponding to the desired pay rate or action:\n");
	printf("1) $%.2f                 2) $%.2f\n", CHOICE1, CHOICE2);
	printf("3) $%.2f                4) $%.2f\n", CHOICE3, CHOICE4);
	printf("5) %s\n", CHOICE5);
	printf("***************************************************************\n\n");

//方法一 
/*	while (i)
	{
		scanf("%d", &choice);
			switch (choice)
		    {
				case 1 : s_ph = CHOICE1; i = 0; break;	
				case 2 : s_ph = CHOICE2; i = 0; break;			
				case 3 : s_ph = CHOICE3; i = 0; break;	
				case 4 : s_ph = CHOICE4; i = 0; break;	
				case 5 : goto over;	
		    	default: printf("Please enter your choice again!\n");	
			}
	}  */

//方法二	用出口循环更好 
	do
	{
		scanf("%d", &choice);
			switch (choice)
		    {
				case 1 : s_ph = CHOICE1; break;	
				case 2 : s_ph = CHOICE2; break;			
				case 3 : s_ph = CHOICE3; break;	
				case 4 : s_ph = CHOICE4; break;	
				case 5 : goto over;	
		    	default: printf("Please enter your choice again!\n");	
			}
	}while(choice < 1 || choice > 5);
	
	printf("Please enter the workhours in a week: ");
	scanf("%d", &hour) ;
	if (hour <= OT)
	{
		salary = s_ph * hour;
		
		if (salary <= BREAK1)
			tax = salary * RATE1;
		else
			tax = TAX1 + (salary - BREAK1)*RATE2;
	}
	else
	{
		salary = OT * s_ph + (hour - OT) * OTTR * s_ph;
		
		if (salary <= BREAK2)
			tax = TAX1 + (salary - BREAK1) * RATE2;
		else
			tax = TAX2 + (salary - BREAK2) * RATE3;
		
	}
	ni = salary - tax;
	printf("salary = %f, tax = %f, net income = %f\n", salary, tax, ni);
	
	over: return 0;
}
