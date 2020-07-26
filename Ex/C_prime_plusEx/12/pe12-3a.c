# include <stdio.h>

void set_mode(int * pre, int m)
{
	if (m > 1 || m < 0)
	{
		printf("Invlalid mode specified. Mode %d(%s) used.\n", *pre, *pre == 0 ? "metric" : "US" );
		
	}
	else 
		*pre = m;
			
}

void get_info(double * dis, double * fuel, int m)
{
	
	if (0 == m)
	{
		printf("Enter distance traveled in kilometers:") ;
		scanf("%lf", dis);
		printf("Enter fuel consumed in liters:");
		scanf("%lf", fuel);
	}
	else
	{
		printf("Enter distance traveled in miles:");
		scanf("%lf", dis);
//		printf("%.1f\n", dis);
		printf("Enter fuel consumed in gallons:");
		scanf("%lf", fuel);
//		printf("%.1f\n", fuel);
	}

}

void show_info(double dis, double fuel, int m)
{
	if (0 == m)
		printf("Fuel consumption is %.2f liters per 100 km.\n", (fuel /dis) * 100);
	else
		printf("Fuel consumption is %.1f mile per gallon.\n", dis / fuel);
}

