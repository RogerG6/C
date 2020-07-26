# include <stdio.h>
# include <string.h>
# define SIZE 50
void tfer_st(char * st);
void s_gets(char * st, int n);

int main(void)
{

	char str[SIZE];
	s_gets(str, SIZE);
	puts(str);
	tfer_st(str);    //为什么只要调用就出错？ 
	puts(str) ;

	return 0;
}

/*void tfer_st(char * st)
{
	char * end, tem ;
	int ct = 1;
	int len;
	
	len = strlen(st);
	
	end = st + len -1;
    
	while (ct++ <= (len / 2))
	{
	//	printf("%d\n",len);
		tem = *st;
		*st = *end;
		*end = tem;
		end--;
		st++;  
		
	}
		
}*/


void tfer_st(char * st)
{
	int len = strlen(st);
	int i = 0;
	char temp;
	
	for (i = 0; i < len/2; i++)   //用for 方便 
	{
		temp = st[i];
		st[i] = st[len-1-i];
		st[len-1-i] = temp;
	}
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
