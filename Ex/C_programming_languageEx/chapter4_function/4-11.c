/* Date：2020/3/4 
 * 4－11：修改getop函数，使其不必使用ungetch函数。提示：可以使用一个static类型的内部变量解决该问题
 */ 
 
int getop(char s[])
{
	int i, c;
	static int lastc = 0;		//存放压回的字符 
	
	if (lastc == 0)
		c = getchar();
	else
	{
		c = lastc;
		lastc = 0;
	}
	/* 跳过空白 */ 
	while ((c = getch()) == ' ' || c == '\t')	
		;
	
	i = 0;
	/* 非数字 */ 
	if (!isdigit(c) && c != '.' && c != '-')
		return c;
		
	/* 负数 */ 
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
	
	
	/* 整数 */
	if (isdigit(c))
	{
		do
			s[i++] = c;
		while (isdigit(c = getch()));
	}
			
	/* 小数 */ 
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

