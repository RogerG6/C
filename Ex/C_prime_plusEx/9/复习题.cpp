/*2
a. void donut(int);
b. int gear(int, int);
c. int guess(void);
d. void stuff_it(double, double *);

3
a. char n_to_char(int);
b. int digit(double, int);
c. double * which(double *, double *);
d. int random(void);

4
int sum(int i, int j)
{
	return i+j;
}

5
double sum(double i, double j)
{
	return i+j;
}

6
void alter(int * x, int * y)
{
	int sum;
	
	sum = *x + *y;
	*y  = *x - *y;
	*x = sum;
}

7
void salami(int num)
{
	int count;
	for (count = 1; count <= num; count++)
		printf("O salami mio!\n");
}

8
int tmax(int i, int j, int k)
{
	int max;
	max = (i > j ? i : j);
	
	return (max > k ? max : k);
} */

//9

# include <stdio.h>
 void print(void);
  int limit(int low, int up);
  
  int main()
  {
  	print();
  	
  	printf("%d\n", limit(1, 4));
  	
  	return 0;
  }
  void print(void)
	{
		printf("Please choose one of the following:\n");
		printf("1) copy files            2) move files\n");
		printf("3) remove files          4) quit\n");
		printf("Enter the number of your choice:");
	}
	
  int limit(int low, int up)
	{
		int ch, right;
		
		if (scanf("%d", &ch) == 1)
			while (ch < low || ch > up)
			{
				print()	;
				scanf("%d", &ch);
			}		
		else
			ch = 4;
			
		return ch;
	}

