/* Date：2020/3/10 
 * 5-13：编写程序tail，将其输入中的最后n行打印出来。默认情况下，n的值为10，但可以通过一个可选参数改变n的值，因此，命令：
 *	  tail -n
 *	  将打印其输入的最后n行。无论输入或n的值是否合理，该程序都能正常运行。编写的程序要充分利用存储空间；输入的存储方式
 *	  应该同5.6节中排序程序的存储方式一样，而不采用固定长度的二维数组。
 */ 
#include <stdio.h>
#include <string.h>
#include <stdlib.h> 

#define MAXLINES 500	//最多输入行 
#define MAXLEN   1000	//一行最多输入长度 
#define DEFLINES  10

int readlines(char *lineptr[], int maxlines);
int getline(char *line, int maxlen);


int main(int argc, char *argv[])
{
	int i;
	int n;		//打印的行数
	int nlines = 0;		// 输入的总行数 
	int len;	 
	int first;	//最后n行中第一行的索引 
	int last;	// 最后一行str的指针的索引 
	char *p;
	char *buf;	//指向存储字符串的缓冲区 
	char *bufend;
	char line[MAXLEN];
	char *lineptr[MAXLINES] ;
	
	// 判断agrc的情况 
	if (argc == 1)
		n = DEFLINES;
	else if (argc == 2 && argv[1][0] == '-') 
		n = atoi(argv[1] + 1);
	else
	{
		printf("Usage: tail -n\n");
		return -1;
	}
	
	// 判断n的合法性  
	if (n < 1 || n > MAXLINES)
		n = MAXLINES;
		
	// 初始化lineptr
	for (i = 0; i < MAXLINES; i++) 
		lineptr[i] = NULL;
		
	// 分配buf的空间
	if ((p = buf = malloc(MAXLINES * MAXLEN)) == NULL) 
	{
		printf("error: can't alloc memory\n");
		return -1;
	}
	
	last = 0;
	bufend = buf + MAXLINES * MAXLEN;
	
	// 读行
	while ((len = getline(line, MAXLEN)) > 0)
	{
		//printf("Here\n");	
		if ((p + len + 1) >= bufend) 
			p = buf;			// 循环存放
		strcpy(p, line);
		lineptr[last] = p;
		if (++last >= MAXLINES)
			last = 0;			// 循环存放
		p += len + 1;
		nlines++;
	}
	
	// n与nlines比较
	if (n > nlines) 
		n = nlines;
	
	// 打印最后的n行
	first =  last - n;
	if (first < 0) 
		first += MAXLINES;
	
	for (i = first; n--; i = (i + 1) % MAXLINES)
		printf("%s", lineptr[i]);
		
	return 0;
}



int getline(char *line, int maxlen)
{
	int c, i;
	
	for (i = 0; i < maxlen - 2 && (c = getchar()) != EOF && c != '\n'; i++) 
		line[i] = c;
	
	if (c == '\n')
		line[i++] = c;
	
	line[i] = '\0';
		
	return i;
}


