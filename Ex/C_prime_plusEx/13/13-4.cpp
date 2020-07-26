//逐个显示命令行参数的文件内容 
# include <stdio.h>
# include <stdlib.h>

int main(int argc, char * argv[])
{
	FILE * fp;
//	int c;
	char tmp[1024];
	
	for (int i = 1; i < argc; i++)
	{
		if ((fp = fopen(argv[i], "rb")) == NULL)
		{
			printf("Cant open %s", argv[i]);
			continue;
		}
	//	while ((c = getc(fp)) != EOF)   //逐个字符读取显示，速度慢，有点卡 
	//		putc(c, stdout);
		while (fgets(tmp, 1024, fp) != NULL)   //读取字符串，显示速度快 
			fputs(tmp, stdout);
	}
	
	return 0;
}
