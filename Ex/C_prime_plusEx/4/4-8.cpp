# include <stdio.h>
# define G_L 3.785  //gallon to liter
# define M_K 1.609  //mile to kilometer

int main(void)
{
	float dis, gas;
	
	printf("Please enter your distance and volume of gasoline: ");
	scanf("%f %f", &dis, &gas);
	printf("Miles per gallon: %0.1f\n", dis/gas);
	
	printf("Liters per 100 kilometers: %0.1f\n", 100*(gas*G_L)/(dis*M_K));
	
	return 0;
}

/*��Dev��C++5.10�����н��Ϊ��
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Please enter your distance and volume of gasoline: 50 100
Miles per gallon: 0.5
Liters per 100 kilometers: 470.5

--------------------------------
Process exited after 5.818 seconds with return value 0
�밴���������. . .

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
