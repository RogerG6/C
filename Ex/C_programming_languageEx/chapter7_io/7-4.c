/* Date：2020/3/17
 * 7-4：类似于上一节中的函数minprintf，编写scanf函数的一个简化版本
 */ 
#include <stdio.h> 
#include <stdarg.h>
#include <ctype.h>

#define MAXLENS 100

int minscanf(char *fmt, ...);

int main(void)
{
	int ival, year, month, day, err;
	double dval;
	char str[MAXLENS];
#if 1
	printf("Enter int, double, string:");
	err = scanf("%d%lf%s", &ival, &dval, str);
	printf("ival = %d\ndval = %lf\nstr = %s\nerr = %d\n", ival, dval, str, err);
#elif 0
	printf("Enter date(y/m/d):");
	err = minscanf("%d/%d/%d", &year, &month, &day);
	printf("date: %d/%d/%d\n", year, month, day);
#endif	
	return 0;
}

int minscanf(char *fmt, ...)
{
	va_list ap;
	char *p, *pm;
	int *ip; 
	double *dp;
	char *s;
	char localfmt[MAXLENS];
	int i, c;
	
	va_start(ap, fmt);
	for (p = fmt; *p; p++){
		if (*p != '%' && *p == (c = getchar()))
			continue;
		if (*p != '%'){
			putchar(*p);
			putchar(c);
			printf("error: invalid input\n");
			return -1;
		}
		if (*p == '%'){
			// 将格式化写入localfmt 
			i = 0;
			pm = p;
			localfmt[i++] = *pm;
			while (isalnum(*++pm))
				localfmt[i++] = *pm;
			localfmt[i] = '\0';
			printf("fmt = %s\n", localfmt);
			
			switch (*++p){
				case 'd':
					ip = va_arg(ap, int *);
					scanf(localfmt, ip);
					break;
				case 'f':
					dp = va_arg(ap, double *);
					scanf(localfmt, dp);
					break;
				case 's':
					s = va_arg(ap, char *);
					scanf(localfmt, s);
					break;
				default :
					break;
			}
		}
		
	}
	va_end(ap);
}
