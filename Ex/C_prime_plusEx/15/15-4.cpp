# include <stdio.h>
int open_close(int n, int bit)
{
	n >>= bit - 1;
	if (n & 01 == 1 )
		return 1;
	else
		return 0;
}
int main(void)
{
	int num, bit;
	puts("Enter a number.");
	while (scanf("%d", &num) != 1)
		puts("Please enter a integar");
	
	puts("Enter a bit number.");
	while (scanf("%d", &bit) != 1)
		puts("Please enter a integar");
	
	printf("No.%d bit of %d is %s\n", bit, num, (open_close(num, bit) == 1 ? "Open" : "Close"));
	return 0;
}
