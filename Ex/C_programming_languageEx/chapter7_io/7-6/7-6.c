/* Date：2020/3/20
 * 7-6：编写一个程序，比较两个文件并打印它们第一个不相同的行
 */ 
#include <stdio.h> 
#include <string.h>

#define MAXLEN 100

int main(void)
{
	FILE *fp1, *fp2;
	char file1[] = "a.txt";
	char file2[] = "b.txt";
	char line1[MAXLEN], line2[MAXLEN];
	char *lp1, *lp2; 
	
	if ((fp1 = fopen(file1, "r")) == NULL){
		printf("Can't open file %s", file1)	;
		return -1;
	}
	
	if ((fp2 = fopen(file2, "r")) == NULL){
		printf("Can't open file %s", file2)	;
		return -1;
	}
	
	do {
		lp1 = fgets(line1, MAXLEN, fp1);
		lp2 = fgets(line2, MAXLEN, fp2);
		
		if (lp1 == line1 && lp2 == line2){
			if (strcmp(line1, line2) != 0){
				printf("first difference in line\n%s\n", line1);
				lp1 = lp2 = NULL;
			}
		}
		else if (lp1 != line1 && lp2 == line2)
			printf("end of first file at line\n%s\n", line2);
		else if (lp1 == line1 && lp2 != line2)
			printf("end of second file at line\n%s\n", line1);
	}while (lp1 == line1 && lp2 == line2);

	return 0;
}
