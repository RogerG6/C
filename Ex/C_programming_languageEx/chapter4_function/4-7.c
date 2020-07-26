/* Date：2020/2/17
 * 4-7: 编写一个函数ungets(s)，将整个字符串s压回到输入中。ungets函数需要使用buf和bufp吗？
 *		它能仅使用ungetch函数？ 
 */ 
 
/* 用于ungetch的缓冲区 */ 
char buf[BUFSIZE];
int bufp = 0;

int getch(void)
{
	return (bufp > 0 ? buf[--bufp] : getchar());
}

void ungetch(int c)
{
	if (bufp >= BUFSIZE)
		printf("ungetch: too many characters\n");
	else
		buf[bufp++] = c;
}

void ungets(char s[])
{
	int len = strlen(s);
	while (len > 0)
		ungetch(s[--len]);
}
