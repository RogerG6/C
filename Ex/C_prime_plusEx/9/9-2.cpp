# include <stdio.h> 
void chline(char ch, int i, int j);

int main(void)
{
	chline('A', 5, 3);
	
	return 0;
}

void chline(char ch, int i, int j)  //¥Ú”° A j –– i ¡– 
{
	int a, b;
	
	for ( a = 1; a <= j; a++) 
	{
		for (b = 1; b <= i; b++)
			putchar(ch);
		putchar('\n');
	}	
}

