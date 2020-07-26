# include <stdio.h> 
# include <string.h>
# define SIZE 20
void dele_space(char * st);
void s_gets(char * st, int n);

int main(void)
{
	char str[SIZE] ;
	int c;
	do
	{
		
		s_gets(str, SIZE);
		dele_space(str);
		
		puts(str);
		puts("Press c to continue, enter to quit!");
		c = getchar();
		while (c != '\n')
			c = getchar();
	} while (c != '\n');  //空行终止 
	
	return 0;
}

void dele_space(char * st)
{
	char * sp, * start;  //space 的地址 
	start = st;
	while (*st != '\0')
	{
		
		if (*st == ' ')
		{
			sp = st;
			
			while (*sp != '\0')
			{
				*sp = *(sp + 1);  //此处不能用*++sp 
				sp++;
			//	puts(sp);
			}
		}
		st++;
	}
//	puts(start);
}

void s_gets(char * st, int n)
{
	
	if(fgets(st, n, stdin))
	{
			while (*st != '\n' && *st != '\0')
				st++;
			if (*st == '\n')
				*st = '\0';
			else
				while (getchar() != '\n')
					continue;
	}
}

//=========================================================================================================================
//标准答案：
/* Programming Exercise 11-10 */
#include <stdio.h>
#include <string.h> // for strchr();
#define LEN 81
int drop_space(char * s);
char * s_gets(char * st, int n);
int main(void)
{
	char orig[LEN];
	puts("Enter a string of 80 characters or less:");
	while (s_gets(orig, LEN) && orig[0] != '\0')   //空行终止 
	{
		drop_space(orig);
		puts(orig);
		puts("Enter next string (or just Enter to quit):");
	}
	puts("Bye!");
	return 0;
}
int drop_space(char * s)
{
	char * pos;
	while (*s)                /* or while (*s != '\0') */
	{
		if (*s == ' ')
		{
			pos = s;
			do
			{
				*pos = *(pos + 1);
				pos++;
			} while (*pos);
		}
		else
			s++;
	}
}
char * s_gets(char * st, int n)
{
	char * ret_val;
	char * find;
	ret_val = fgets(st, n, stdin);
	if (ret_val)
	{
		find = strchr(st, '\n');     // look for newline 妙！！！ 
		if (find)                    // if the address is not NULL,
			*find = '\0';            // place a null character there
		else
			while (getchar() != '\n')
				continue;
	}
	return ret_val;
} 
