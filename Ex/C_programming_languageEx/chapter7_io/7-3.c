/* Date��2020/3/17
 * 7-3����дminprintf������ʹ�������printf�ĸ��๦��
 */ 
 
#include <stdarg.h>
#include <stdio.h> 
#include <ctype.h>
#include <string.h> 

#define MAXNUMS	10		//���ֵ����λ�� 

void minprintf(char *fmt, ...);
void printspace(int n);

int main(void)
{
	printf("%-15.10s*\n", "hello world");
	minprintf("%5d\n", 100);
	minprintf("%.3f\n", 100.0);
	minprintf("%-15.10s\n", "hello world\n");
	minprintf("%5o\n", 25);
	minprintf("%3x\n", 25);
	minprintf("%3c\n", 'Z');
	
	return 0;
}

void minprintf(char *fmt, ...)
{
	va_list ap;
	char *p;
	int ival;
	double dval;
	char *str;
	int width = 0, precision = 0;	//�ֿ� ���� 
	int pw;		//��ӡ�Ŀ�� 
	int left = 0, i;
	//char num[MAXNUMS];
	
	va_start(ap, fmt);
	for (p = fmt; *p; p++){
		if (*p != '%'){
			putchar(*p);
			continue;
		}
		//����Ҷ���
		if (*++p == '-') 
			left = 1;
		else
			p--;
		
		//��С�ֶο�� 
		while (isdigit(*++p)){
			width = 10 * width + (*p - '0');
		}
		
		//����
		if (*p == '.') 
			p++;
			
		while (isdigit(*p)){
			precision = 10 * precision + (*p++ - '0');
		}
		
		switch (*p){
			case 'd' :	//ʮ���� 
				//printspace(width);
				ival = va_arg(ap, int);
				printf("%*d", width, ival);
				break;
			case 'f':	//������ 
				dval = va_arg(ap, double);
				printf("%*.*f", width, precision, dval);
				break;
			case 's':	//�ַ��� 
				str = va_arg(ap, char *);
				if (left){
					//printf("%-*.*s", width, precision, str);
					pw = strlen(str) >= precision ?  precision : strlen(str);
					for (i = 0; i < pw; i++)
						putchar(str[i]);
					i = width - pw;
					while (i-- > 0)
						putchar(' ');					
				}
				else
					printf("%*.*s", width, precision, str);
				break;
			case 'o' :	//�˽��� 
				ival = va_arg(ap, int) ;
				printf("%*o", width, ival);
				break;
			case 'x':
			case 'X':
				ival = va_arg(ap, int) ;
				printf("%*x", width, ival);
				break;
			case 'c':
				ival = va_arg(ap, int) ;
				printf("%*c", width, ival);
				break;
			default :
				if (*p != ' ')
					putchar(*p);
				break;
		}
	}
	va_end(ap);
}

void printspace(int n)
{
	while (n--)
		putchar(' ');
}



