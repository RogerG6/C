/* Date：2020/3/20
 * 7-7: 修改第5章的模式查找程序，使它从一个命名文件的集合中读取输入(有文件名参数时)，
 *      如果没有文件名，则从标准输入读取输入。当发现一个匹配行时，是否应该将相应的文件名打印出来？
 */ 
 
#include <stdio.h>
#include <string.h>

#define MAXLEN 100

void fap(FILE *fp, char *name, char *pattern, int except, int number);

int main(int argc, char *argv[])
{
	FILE *fp;
	int c;
	//char files[] = "files.txt";
	int except = 0;
	int number = 0;

	char pattern[MAXLEN]; 
		
	while (--argc && (*++argv)[0] == '-')
		while (c = *++argv[0])
			switch (c){
				case 'n':
					number = 1;
					break;
				case 'x':
					except = 1;
					break;
				default :
					printf("find: illegal option %c\n", c);
					argc = -1;
					break;
			}
				
	if (argc >= 1)
		strcpy(pattern, *argv);
	else{
		printf("Usage: find -nx filename\n");
		return 1;
	}
	
	if (argc == 1)
		fap(stdin, "", pattern, except, number);
	else {
		while (--argv)		// find pattern in all files
			if ((fp = fopen(*++argv, "r")) == NULL){
				fprintf(stderr, "Can't open file %s\n", *argv);
				return 2;
			}
			else {
				fap(fp, *argv, pattern, except, number);
				fclose(fp);
			}
	}
	return 0;
}

// find pattern
void fap(FILE *fp, char *name, char *pattern, int except, int number)
{
	int lineno = 0;
	char line[MAXLEN];	
	
	while (fgets(line, MAXLEN, fp) != NULL){
		lineno++;
		if ((strstr(line, pattern) != NULL) != except){
			if (*name)
				printf("%s - ", name);
			if (number)
				printf("%d ", lineno);
			printf("%s", line);
		}	
	}
	
}
