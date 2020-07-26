# include <stdio.h>
# define SIZE 8 * sizeof(int)
unsigned int rotate_l(unsigned int x, int left);
void itobs(char * st, unsigned int n);

int main(void)
{
	unsigned int num, move;
	char bin[SIZE + 1];
	
	puts("Enter a number.");
	while (scanf("%d", &num) != 1)
		puts("Please enter a unsinged integar.");
	puts("Enter a number to rotate.");
	while (scanf("%d", &move) != 1)
		puts("Please enter a  integar.");
	itobs(bin, num);
	printf("%d 的二进制为：%s\n", num, bin);
	
	itobs(bin, rotate_l(num, move));
	printf("%d 经旋转后为：%d\n其二进制为：    %s\n",
					num, rotate_l(num, move), bin);
	
	return 0;
}

unsigned int rotate_l(unsigned int x, int left)
{
	unsigned int out = 0;
	
	left %= SIZE;    //keep left valid 
	out = x >> (SIZE - left);
	
	return (x << left) | out;
}

void itobs(char * st, unsigned int n)
{	
	for (int i = SIZE - 1; i >= 0; i--)
	{
		st[i] = (n & 01) + '0';
		n >>= 1;
	}
	st[SIZE] = '\0';
}
