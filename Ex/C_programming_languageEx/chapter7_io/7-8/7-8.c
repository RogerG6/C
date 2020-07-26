/* Date��2020/3/20
 * 7-8: ��дһ�������Դ�ӡһ���ļ����ϣ�ÿ���ļ����µ�һҳ��ʼ��ӡ�����Ҵ�ӡÿ���ļ��ı����ҳ��
 */ 
#include <stdio.h> 
#include <ctype.h>

#define MAXLINE 100		// һ������ַ��� 
#define MAXBOT 3		//һҳ�ײ������� 
#define MAXHDR 5		//һҳͷ�������� 
#define MAXPAGE 66		//һҳ�������� 

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
