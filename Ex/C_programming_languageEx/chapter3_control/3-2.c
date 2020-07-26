/* Date：2020/2/12
 * 3-2: 编写一个函数escape(s, t)，将字符串t复制到字符串s中，并在复制过程中将
 *		换行符、制表符等不可见字符分别转换为\n, \t等相应的可见的转义字符序列
 *		要求使用switch语句
 *		再编写一个具有相反功能的函数，在复制过程中将转义字符序列转换为实际字符 
 */ 
#include <stdio.h> 

/* t cpy to s, 实际字符转换成\n \t */
void escape(char s[], char t[])
{
	int i, j;
	for (i = j = 0; t[i] != '\0'; i++)
	{
		switch(t[i])
		{
			case '\n': 
				s[j++] = '\\';
				s[j++] = 'n';
				break;
			case '\t': 
				s[j++] = '\\';
				s[j++] = 't';
				break;
				
			default  : 
				s[j++] = t[i];
				break;
		}
	}
	s[j] = '\0';
}

/* s cpy to t, \n \t转换成实际字符 */ 
void diescape(char s[], char t[])
{
	int i, j;
	
	for (i = j = 0; s[i] != '\0'; i++)
	{
		switch (s[i])
		{
			case '\\':
				if (s[i+1] == 'n')
				{
					t[j++] = '\n';
					i++;					
				}
				else if (s[i+1] == 't')
				{
					t[j++] = '\t';
					i++;					
				}
				else
					t[j++] = s[i];
				
				break;
			default  :
				t[j++] = s[i];
				break;
		}
	}
	t[j] = '\0';
}

int main(void)
{
	char s[100], t[100], c;
	int i = 0;
	
	printf("Enter a string: ");
	//gets(t);
	while ((c = getchar()) != EOF)
		t[i++] = c;
	t[i] = '\0';
	
	escape(s, t);
	printf("After escape: \ns: %s\nt: %s\n", s, t);
	
	diescape(s, t);
	printf("After diescape: \ns: %s\nt: %s\n", s, t);
		
	return 0;
}

/*
Enter a string: a
b       c
d
^Z
After escape:
s: a\nb\tc\nd\n
t: a
b       c
d

After diescape:
s: a\nb\tc\nd\n
t: a
b       c
d


--------------------------------
Process exited after 7.121 seconds with return value 0
请按任意键继续. . .

*/ 

