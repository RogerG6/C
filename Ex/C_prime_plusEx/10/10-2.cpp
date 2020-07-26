# include <stdio.h>

void copy_arr(double * t1, double * s, int n);
void copy_ptr(double * t2, double * s, int n);
void copy_ptrs(double * t3, double * s, double * se);
void show_arr(double *, int);

int main(void)
{
	double source[5] = {1.1, 2.2, 3.3, 4.4, 5.5};
	double target1[5];
	double target2[5];
	double target3[5];
	
	copy_arr(target1, source, 5);
	copy_ptr(target2, source, 5);
	copy_ptrs(target3, source, source + 5);
	
	printf("target1:\n");
	show_arr(target1, 5);
	printf("target2:\n");
	show_arr(target2, 5);
	printf("target3:\n");
	show_arr(target3, 5);
	printf("\n");
	return 0;
}

void copy_arr(double * t1, double * s, int n)
{
	int i;
	for (i = 0; i < n; i++)
		*(t1 + i) = *(s + i);
}

void copy_ptr(double * t2, double * s, int n)
{
	int i;
	for (i = 0; i < n; i++)
		*(t2 + i) = *(s + i);
}

void copy_ptrs(double * t3, double * s, double * se)
{
	while (s < se)
		*t3++ = *s++;
}

void show_arr(double * p, int n)
{
	int i;
	for (i = 0; i < n; i++) 
		printf("%.1lf  ", *(p + i));
	printf("\n");
}
