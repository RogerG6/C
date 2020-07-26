# include <stdio.h>
# include <stdlib.h>
# include <time.h>
# define SIZE 100
void sort(int * p, int n);
void show_arr(const int * p, int n);

int main(void)
{
	int str[SIZE];
	
	for (int i = 1; i <= SIZE; i++)
	{
		str[i-1] = rand() % 10 + 1;
	}
	sort(str, SIZE);
	show_arr(str, SIZE);
	
	return 0;
}

void sort(int * p, int n)
{
	int i, j, temp;
	for (i = 0; i < n - 1; i++)
		for (j = i + 1; j < n; j++)
		{
			if (p[i] < p[j])
			{
				temp = p[i];
				p[i] = p[j];
				p[j] = temp;
			}
		}
}

void show_arr(const int * p, int n)
{
	int i;
	for (i = 0; i < n; i++)
		printf("%d	", p[i]);
		
	putchar('\n');
}
