1.  ĩβ�޿հ׷�
2.  see you at the snack bar.
	ee you at the snack bar.
	see you
	e you
3.  y
	my
	mmy
	ummy
	Yummy
4.  I read part of it all the way through.
5.a.Ho Ho Ho!!oH oH oH
  b.char *
  c.&("Ho Ho Ho!")
  d.ǰ���ȵݼ���*��Ϊchar;������*�ٵݼ�, Ϊchar *
  e.Ho Ho Ho!!oH oH o
  f.��һ�������ַ����Ƿ�Ϊ�գ��ڶ�������pc�Ƿ�ص��ַ����� 
  g.��ѭ�� 
  h.�������� 
  
6.  sign: 1 byte
	'$': 1 byte
	"$": 2 byte
	
7.  How are ya, sweetie?How are ya, sweetie?
	Beat the clock.
	eat the clock.
	Beat the clock.Win a toy.
	Beat
	chat
	hat
	at
	t
	t
	at 
	How are ya, sweetie?
	
8.  faavrhee
	*le*on*sm
	
9.  char * s_gets(char * st, int n)
	{
		char * ret_val;
		
		ret_val = fgets(st, n, stdin);
		if (ret_val)
		{
			while (*st != '\0' && *st != '\n')
				st++;
			if (*st == '\n')	
				*st = '\0';
			else
				while (getchar() != '\n')
					continue;
		}
		return ret_val;
	}
	
10. int strlen(char * p)
	{
		int count = 0;
		
		while (*p++)
		{
			count++;
		}
		return count;
	}
	
11. char * s_gets(char * st, int n)
	{
		char * ret_val;
		int * p;
		
		ret_val = fgets(st, n, stdin);
		if(ret_val)
		{
			p = strchr(st, '\n');
			if (p)
				*p = '\0'
			else
				while (getchar() != '\n')
					continue;
		}
		return ret_val;
	}
	
12. char * spa(char * str)
	{
		while (*str)
		{
			if (*str == ' ')
				return str;
			str++; 
		}
		return NULL;	
	}






