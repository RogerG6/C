/* Date��2020/2/17
 * 4-8: �ٶ����ֻѹ��һ���ַ�������Ӧ���޸�getch��ungetch��2������ 
 */ 

/* ����ungetch�Ļ����� */ 
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
