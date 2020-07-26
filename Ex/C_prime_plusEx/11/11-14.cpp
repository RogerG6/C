# include <stdio.h>
# include <string.h>
double s_dou(char * st);
int s_int(char * st);

int main(int argc, char * argv[])
{
	int i;
	double base;
	int mi;
	double tot = 1.0;
	
	base = s_dou(argv[1]);
	mi = s_int(argv[2]);
	for (i = 1; i <= mi; i++)
		tot *= base;
	printf("%.1lf 的 %d 次幂为 %.1lf\n", base, mi, tot);
	
	return 0;
}

double s_dou(char * st)
{
	double tot=1, tot2=0;
	char * p;
	
		p = st;
	while (*p != '\0')   //检查是否有小数点 
	{
		if (*p == '.') 
			tot = 0;
		p++;
	} 
	if(tot)      //有小数点则调用要s_int() 
		return (double)s_int(st);
	while (*st != '.')
	{
		tot = 10 * tot + (*st - 48);
		st++;
	}
//	printf("%.1lf\n", tot);
	p = st + strlen(st) - 1;
	while (*p != '.')
	{
		tot2 = (tot2 + (*p - 48)) /10;
		p--;	
	}
	return tot+tot2;
}

int s_int(char * st)
{
	int len ;
	int tot = 0;
	char * p;
	
	len = strlen(st);
	p = st + len -1;
	while (st <= p)
	{
		tot = 10 * tot + (*st -48);
		st ++;
	}
	return tot;
}
