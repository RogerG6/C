/* Date：2020/2/12
 * 3-1: 在上面有关折半查找的例子中，while循环语句内共执行了2次测试，其实
 * 		只要一次就足够(代价是将更多的测试在循环外执行)。重写该函数，使得
 *		在循环内部只执行1次测试。比较2种版本函数的运行时间 
 */ 
 
#include <stdio.h>

int binsearch(int x, int a[], int n)
{
	int low = 0, high = n - 1, mid;
	
	mid = (low + high) / 2;
	while (low <= high && x != a[mid])
	{
		/* x < a[mid] */ 
		high = mid - 1;
		
		/* x > a[mid] */ 
		if (x > a[mid])
			low = mid + 1;
			
		mid = (low + high) / 2;
	}
	
	return low <= high ? mid : -1;
}

int main(void)
{
	int a[10] = {1, 2, 4, 8, 9, 10, 11, 14, 19, 20};
	int n;
	
	printf("Enter a num: ");
	scanf("%d", &n);
	
	printf("%s匹配的值\n", binsearch(n, a, 10) == -1 ? "无" : "有"); 
	
	return 0;
}

/*
Enter a num: 12
无匹配的值

--------------------------------
Process exited after 2.912 seconds with return value 0
请按任意键继续. . .

*/ 
