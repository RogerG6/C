# include <stdio.h>
# include <string.h>
# define LEN 8 * sizeof(int)+1
int  bstoi(const char * pstr);
void itobs(int n, char * pstr);
void show_ar(char * st, int n);

int main(int argc, char * argv[])
{
	int num1, num2;
	char str[LEN];
	
		num1 = bstoi(argv[1]);
		num2 = bstoi(argv[2]); 
		itobs(num1, str);
		printf("Here is %s\n", argv[1]);
		show_ar(str, LEN);
		itobs(num2, str);
		printf("Here is %s\n", argv[2]);
		show_ar(str, LEN);
		
		itobs(~num1, str);
		printf("Here is ~%s\n", argv[1]);
		show_ar(str, LEN);
		
		itobs(~num2, str);
		printf("Here is ~%s\n", argv[2]);
		show_ar(str, LEN);
		
		itobs(num1 & num2, str);
		printf("Here is %s & %s\n", argv[1], argv[2]);
		show_ar(str, LEN);
		
		itobs(num1 | num2, str);
		printf("Here is %s | %s\n", argv[1], argv[2]);
		show_ar(str, LEN);
		
		itobs(num1 ^ num2, str);
		printf("Here is %s ^ %s\n", argv[1], argv[2]);
		show_ar(str, LEN);
		
	
	return 0;
}

int  bstoi(const char * pstr)
{
	int ret = 0;
	int size = strlen(pstr);
	
	for (int i = 0; i < size; i++)
	{
		ret = 2 * ret + ((((pstr[i] - '0') & 01) == 0) ? 0 : 1);
	}
	return ret;
}

void itobs(int n, char * pstr)
{
	for (int i = LEN - 2; i >= 0; i--)
	{
		pstr[i] = (n & 01) + '0';
		n >>= 1;
	}
	pstr[LEN-1] = '\0';
}

void show_ar(char * st, int n)
{
	for (int i = 0; i < n-1; i++)
	{
		putchar(st[i]);
		if ((i + 1) % 4 == 0)
			putchar(' ');
	}
	putchar('\n');
}



