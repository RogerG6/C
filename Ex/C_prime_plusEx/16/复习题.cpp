1.  a. dist = 5280 * miles;
	b. plort = 4 * 4 + 4;
	c. ��Ч����
	d. y = y + 5;
	   berg = berg + 5 * lob;
	   est = berg + 5 / y + 5;
	   nilp = lob * -berg + 5;
2.  # define NEW(X)  ((X) + 5)
3.  # define MIN(X, Y)  ((X) < (Y) ? (X) : (Y)) 
4.  # define EVEN_GT(X, Y) ((X) % 2 == 0 && (X) > (Y) ? 1 : 0)
5.  # define MUL(A, B) printf(#A"is %d and" #Y"is %d\n", A, B)
6.  a. #define CON 25
	b. # define SPACE ' '
	c. # define PS() printf(" ")
	d. # define BIG(X) ((X) + 3)
	e. # define SUMSQ(X, Y) ((X)*(X) + (Y)*(Y))
7.  # define PR(X) printf("name:"#X"; value: %d; address: %p", X, &X)
8.  ע��
	# define SKIP
	#ifndef SKIP
		//code to skip
	#endif
9.  #ifdef PR_DATE
		printf("Date = %s\n", __DATE__);
	#endif
10. ��һ�֣�return double ����
	�ڶ��֣�return (int)(x * x) �Ƚ�ֵת��Ϊint,��תΪdouble
	������: return (int (x*x + 0.5)) �Ƚ�ֵ�������룬��תΪint,���תΪdouble 
11. # define BOOL(X) _Generic((X), bool: "boolean", default: "not boolean")
12. # include <stdio.h>
	# include <math.h>
	# include <stdlib.h>
	int main(int argc, char * argv[])
	{
		float f;
		f = atof(argv[1]);
		if (f > 0)
			printf("The square root of %s is %f", argv[1], sqrt(f));
		return 0;
	}
13. a. qsort((void *)scores, (size_t)1000, sizeof(int), comp);
	b. int comp(const void * p1, const void * p2)
	   {
	   		const int * pt1 = (const int * )p1;
	   		const int * pt2 = (const int * )p2;
	   		
	   		if (*pt1 == *pt2)
	   			return 0;
	   		else if (*pt1 > *pt2)
	   			return 1;
	   		else
	   			return -1;
	   }
14. a. memcpy(data1, data2, 100 * sizeof(double));
	b. memcpy(data1, data2 + 200, 100 * sizeof(double));
