# include <stdio.h>
# define RATE1 0.15
# define RATE2 0.2
# define RATE3 0.25
# define OT 40
# define OTTR 1.5
# define S_PH 10.00
# define S_WT 400
# define BREAK1 300
# define BREAK2 450
# define TAX1 BREAK1 * RATE1
# define TAX2 TAX1 + (BREAK2-BREAK1) * RATE2

int main(void)
{
	int hour;
	float salary, tax, ni;  //ni Ϊ net income
	
	printf("Please enter the workhours in a week: ");
	scanf("%d", &hour) ;
	if (hour <= OT)
	{
		salary = S_PH * hour;
		if (salary <= BREAK1)
			tax = salary * RATE1;
		else
			tax = TAX1 + (salary - BREAK1)*RATE2;
	}
	else
	{
		salary = S_WT + (hour - OT) * OTTR * S_PH;
		if (salary <= BREAK2)
			tax = TAX1 + (salary - BREAK1) * RATE2;
		else
			tax = TAX2 + (salary - BREAK2) * RATE3;
		
	}
	ni = salary - tax;
	printf("salary = %f, tax = %f, net income = %f\n", salary, tax, ni);
	
	
	return 0;	
}
