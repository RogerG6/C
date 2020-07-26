# include <stdio.h>
# include <string.h>
int bstoi(const char * pstr);

int main(void)
{
	const char * pbin = "01001001";
	
	printf("%s的十进制为：%d\n", pbin, bstoi(pbin));
	return 0;
}

int bstoi(const char * pstr)
{
	int ret = 0;
	int size = strlen(pstr);
	
	for (int i = 0; i <= size - 1; i++)
	{
		ret = ret * 2 + (pstr[i] - '0');
	}
	return ret;
}
