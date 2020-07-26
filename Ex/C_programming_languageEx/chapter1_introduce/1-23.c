/* Date：2020/3/24
 * 1-23：编写一个删除C语言程序中所有注释语句。要正确处理带有引号的字符串与字符常量。在C语言中，注释不允许嵌套
 */
#include <stdio.h>

void echo_quote(int c);
void rcomment(int c);
void in_comment(void);

int main(void)
{
	int c;
	
	while ((c = getchar()) != EOF)
		rcomment(c);
	return 0;
}

void rcomment(int c)
{
	int d;
	
	if (c == '/'){
		if ((d = getchar()) == '*')	// 注释 
			in_comment();
		else if (d == '/')		// 递归 
			rcomment(d);
		else {					 
			putchar(c);
			putchar(d);
		}
	}
	else if (c == '\'' || c == '"')	// 字符串或字符串常量 
		echo_quote(c);
	else
		putchar(c);
}

void in_comment(void)
{
	int c = getchar();	//pre char
	int d = getchar();	//current char
	
	while (c != '*' || d != '/') {
		c = d;
		d = getchar();
	}
}

void echo_quote(int c)
{
	int d;
	
	putchar(c);
	while ((d = getchar()) != c) {
		putchar(d);
		if (d == '\\')
			putchar(getchar());
	}
	putchar(d);
}


