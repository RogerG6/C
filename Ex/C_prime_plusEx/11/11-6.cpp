# include <stdio.h>
int is_within(char * st, int c);

int main(void)
{
	char str[81];
	int c;
	
	do
	{
		puts("Enter a string:");  //read string
		fgets(str, 81, stdin);  
		puts("Enter a char:");   //read a char
		c = getchar();
		while (getchar() != '\n')
			;
			
		if (is_within(str, c))  //within string or not
			printf("%c is in string!\n", c);
		else
			printf("%c is not in string!\n", c);
		puts("Press y to continue, q to quit!");
		
		c = getchar();          //continue or not 
		while (getchar() != '\n')
			;
	}while (c != 'q');
	
	return 0;
}

int is_within(char * st, int c)
{
	while (*st != c && *st != '\0')
		st++;
	return *st;
}
