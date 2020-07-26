# include <stdio.h>
# include <time.h>
# include <stdlib.h>
# include <string.h>
# include <stdbool.h>
# define SLEN 11
void rand_choice(int * p, int len, int times);

int main(void)
{
	int a[SLEN];
	int times;
	
	for (int i = 0; i < SLEN; i++)
		a[i] = 2 * i + 1;
	a[4] = 0;
	
	puts("Original array:");
	for (int i = 0; i < SLEN; i++)
		printf("%d ", a[i]);
	putchar('\n');
	puts("Enter a number of choose times.");
	while (scanf("%d", &times) != 1)
		puts("Enter a number of choose times.");
	rand_choice(a, SLEN, times);
	
	return 0;
}

void rand_choice(int * p, int len, int times)
{
	srand((unsigned int)time(0));
	int tmp, random;
	
	if (times > len - 1)
		times = len -1 ;
	for (int i = 0; i < times; i++)
	{
		random = rand() % (len - 1);   //最后一个元素不参加抽取 
		tmp = p[random];
		printf("%d ", tmp);
		p[random] = p[len - 1];   //与最后一个元素交换 
		p[len -1] = tmp;
		len--;    //扔掉最后一个元素 
	}
}
/*void rand_choice(int * p, int len, int times)
{
	srand((unsigned int) time(0));
	int random, i, j;
	int num[times];
	for ( int k = 0; k < times; k++)
	{
		num[k] = -1;
	}

	bool flag = true;
	
	for ( i = 0, j = 0; i < times; i++)
	{
		random = rand() % len;
		for (int n = 0; n < times; n++)
		{
			if (random == num[n])
			{
				flag = false;
				break;
			}
			
		}
		if (flag)
		{
			printf("%d ", p[random]);
			num[j++] = random;
			
		}	
		else
			i--;
		
		flag = true;  //需重设flag 
	}
	
}*/
