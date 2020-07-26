# include <stdio.h>
# include <ctype.h>
char get_first(void);
void f1(void){puts("a");}
void f2(void){puts("b");}
void f3(void){puts("c");}
void f4(void){puts("d");}

int main(void)
{
	void (* pf[4])(void) = {f1, f2, f3, f4};   //用函数指针数组比switch更方便 
	int ch;
	do
	{
		printf("Here is the function you can choose.\nEnter your choice: \n");
		printf("a) f1        b) f2\n");
		printf("c) f3        d) f4\ne) Quit\n");
		ch = get_first();
		if (ch >= 'a' && ch <= 'd')
			(*pf[ch - 'a'])();
	} while (ch != 'e');
}

char get_first(void)
{
	int ch;
	while (isspace(ch = getchar()))
		continue;
	while (getchar() != '\n')
		continue;
	return tolower(ch);
}


