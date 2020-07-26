# include <stdio.h>
int main(void)
{
	int n_ei = 0;
	char c, c_pre;
	
	while((c = getchar()) != '#')
	{
		if ('i' == c)
			if ('e' == c_pre)
				n_ei++;
		c_pre = c;    //c_pre 往后移一位 
	}
	printf("ei出现的次数为： %d\n", n_ei);
	
	return 0;
}
