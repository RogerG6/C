# include <stdio.h>
int main(void)
{
	int age;
	double seconds;
	
	while(1)
	{
	scanf("%d", &age);
	seconds = 3.156e7 * age;
	printf("���任���������%e\n", seconds);	
	}
	
	return 0;
}
