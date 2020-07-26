# include <stdio.h>
# include <stdlib.h>
# include <time.h>
void n_count(int n);
int n1 = 0,n2 = 0, n3 = 0, n4 = 0, n5 = 0, n6 = 0, n7 = 0, n8 = 0, n9 = 0, n10 = 0;

int main(void)
{
	int i = 1, j, k;
	
	
	while (i < 11)
	{
		int ten[10] = {0};
		n1 = 0,n2 = 0, n3 = 0, n4 = 0, n5 = 0, n6 = 0, n7 = 0, n8 = 0, n9 = 0, n10 = 0;
		scanf("%d", &k);    //每次读取不同的种子 
		srand(k);
		for (j = 0; j < 1000; j++)
		{
//			n_count(rand() % 10 + 1);	
			ten[rand() % 10]++;         //利用产生的随机数与下标的关系可减少代码量 
		}
		printf("第%d次：\n", i++);
//		printf("1      2      3      4      5      6      7      8      9      10\n");
//		printf("%-7d%-7d%-7d%-7d%-7d%-7d%-7d%-7d%-7d%-7d\n",
//		n1, n2, n3, n4, n5, n6, n7, n8, n9, n10);
		for(int m = 0; m < 10; m++)
			printf("%d 出现的次数为：%d\n", m, ten[m]);
	}
	
	return 0;
}

void n_count(int n)
{
	switch(n)	
	{
		case 1: n1++; break;
		case 2: n2++; break;
		case 3: n3++; break;
		case 4: n4++; break;
		case 5: n5++; break;
		case 6: n6++; break;
		case 7: n7++; break;
		case 8: n8++; break;
		case 9: n9++; break;
		case 10: n10++; break;
	}
}
