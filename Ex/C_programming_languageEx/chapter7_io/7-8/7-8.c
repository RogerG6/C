/* Date：2020/3/20
 * 7-8: 编写一个程序，以打印一个文件集合，每个文件从新的一页开始打印，并且打印每个文件的标题和页数
 */ 
#include <stdio.h> 
#include <ctype.h>

#define MAXLINE 100		// 一行最多字符数 
#define MAXBOT 3		//一页底部的行数 
#define MAXHDR 5		//一页头部的行数 
#define MAXPAGE 66		//一页最多的行数 

void fileprint(FILE *fp, char *fname);
int heading(char *fname, int pageno);

int main(int argc, char *argv[])
{
	FILE *fps, *fp;
	
	if (argc == 1) 
		fileprint(stdin, "");
	else {
		while (--argc)
			if ((fp = fopen(*++argv, "r")) == NULL)	{
				fprintf(stderr, "can't open file %s\n", *argv);
				return 1;
			}
			else {
				fileprint(fp, *argv);
				fclose(fp);
			}
	}
	
	return 0;
}

void fileprint(FILE *fp, char *fname)
{
	int lineno, page = 1;
	char line[MAXLINE];
	
	lineno = heading(fname, page);
	while (fgets(line, MAXLINE, fp) != NULL){
		if (lineno == 1) {
			fprintf(stdout, "\f");
			lineno = heading(fname, page);
		}
		fputs(line, stdout);
		if (++lineno > MAXPAGE - MAXBOT)
			lineno = 1;
	}
	fprintf(stdout, "\f");	
}

int heading(char *fname, int pageno)
{
	int ln = 3;
	
	fprintf(stdout, "\n\n");
	fprintf(stdout, "%s		page %d\n", fname, pageno);
	while (ln++ < MAXHDR)
		fprintf(stdout, "\n");
	return ln;
}
