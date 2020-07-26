/* Date��2020/3/4 
 * 4��11���޸�getop������ʹ�䲻��ʹ��ungetch��������ʾ������ʹ��һ��static���͵��ڲ��������������
 */ 
 
int getop(char s[])
{
	int i, c;
	static int lastc = 0;		//���ѹ�ص��ַ� 
	
	if (lastc == 0)
		c = getchar();
	else
	{
		c = lastc;
		lastc = 0;
	}
	/* �����հ� */ 
	while ((c = getch()) == ' ' || c == '\t')	
		;
	
	i = 0;
	/* ������ */ 
	if (!isdigit(c) && c != '.' && c != '-')
		return c;
		
	/* ���� */ 
	if (c == '-') 
	{		
		if (isdigit(c = getch()) || c == '.')
			s[i++] = '-';
		else
		{
			if (c != EOF)
			{		
				lastc = c ;
				return '-';
			}
		}	
	}
	
	
	/* ���� */
	if (isdigit(c))
	{
		do
			s[i++] = c;
		while (isdigit(c = getch()));
	}
			
	/* С�� */ 
	if (c == '.')
	{
		do
			s[i++] = c;
		while (isdigit(c = getch()));
	}
	
	s[i] = '\0';
	if (c != EOF)
		lastc = c;
	
	return NUMBER;
}

