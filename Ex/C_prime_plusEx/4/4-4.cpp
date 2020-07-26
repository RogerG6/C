# include <stdio.h> 
//# define NAME "Dabney"
int main(void)
{
	float tall;
	char name[6];
	
	printf("Please enter your name and tall:");
	scanf("%s %f", name, &tall);
	printf("%s, you are %0.3f feet tall\n", name, tall);
	printf("%s, you are %0.3f meters tall or %0.3f centmeters tall\n", name, tall/100, tall);
	
	return 0;
}
