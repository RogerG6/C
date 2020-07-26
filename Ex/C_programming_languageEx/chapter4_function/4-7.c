/* Date��2020/2/17
 * 4-7: ��дһ������ungets(s)���������ַ���sѹ�ص������С�ungets������Ҫʹ��buf��bufp��
 *		���ܽ�ʹ��ungetch������ 
 */ 
 
/* ����ungetch�Ļ����� */ 
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
