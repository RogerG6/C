/* Date：2020/2/17
 * 4-8: 假定最多只压回一个字符。请相应地修改getch与ungetch这2个函数 
 */ 

/* 用于ungetch的缓冲区 */ 
char buf = '\0';


int getch(void)
{
	int c;
	
	if (buf != '\0') 
		c = buf;
	else
		c = getchar();
	buf = '\0';
	
	return c;
}

void ungetch(int c)
{
	if (buf == '\0')
		buf = c;
	else
		printf("only one characters be stored\n");
}
