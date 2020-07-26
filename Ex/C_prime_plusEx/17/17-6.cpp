# include <stdio.h> 
void sort(int a[], int n);
void showarr(int a[], int n);
int seek(int a[], int n, int goal);

int main(void)
{
	int a[10] = {1, 5, 3, 9, 7, 4, 10, 23, 34, 45};
	int target;
	
	sort(a, 10);
	puts("enter a number that you want to seek:");
	while (scanf("%d", &target) != 1)
		continue;
	showarr(a, 10);
	printf("return: %d\n", seek(a, 10, target));
	
	return 0;
}

void sort(int a[], int n)
{
	int i, j, tmp;
	for (i = 0; i < n-1; i++)
	{
		for (j = i + 1; j < n; j++)
		{
			if (a[i] > a[j])
			{
				tmp = a[i];
				a[i] = a[j];
				a[j] = tmp;
			}
		}
	}
}

int seek(int a[], int n, int goal)   //二分法查找
{
	int low = 0;
	int high = n - 1;
	int seek;
	int ct = 0;
	
	while ((low + 1) != high)
	{
//		printf("%d\n", ++ct);
		seek = (low + high) / 2;
		
		if (goal > a[seek])
		{
			low = seek;
		}
		else if(goal < a[seek])
		{
			high = seek;
		}
		else
			return 1;
		if (goal == a[low] || goal == a[high])
			return 1;
	}
	return 0;
} 
void showarr(int a[], int n)
{
	for (int i = 0; i < n; i++)
		printf("%d ", a[i]);
	putchar('\n');
}
