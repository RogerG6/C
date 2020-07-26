/* Date：2020/3/24 
 * 1-22：编写一个程序，把较长的输入行“折”成短一些的两行或多行，折行的位置在输入行的第n列之前的最后一个非空格符之后。
 *	     要保证程序能够智能地处理输入行很长以及在指定的列前没有空格或制表符的情况 
 */ 
 
#include <stdio.h>
#include <string.h> 
#define TABINC 4
#define MAXCOL 10

int newpos(int pos);
void printl(int pos);
int exptab(int pos);
int findblnk(int pos);

char line[MAXCOL];

int main(void)
{
	int c;
	int pos = 0;
	
	while ((c = getchar()) != EOF) {
		line[pos] = c;
		if (c == '\n') {
			printl(pos);		//打印当前行 
			pos = 0;			
		} else if (c == '\t') {
			pos = exptab(pos);	// 扩展TAB为4个空格 
		} else if (++pos >= MAXCOL) {
			pos = findblnk(pos);
			printl(pos);
			pos = newpos(pos);
		}
	}
	return 0;
}

void printl(int pos)
{
	int i;
	for (i = 0; i < pos; i++)
		putchar(line[i]) ;
		
	/* 如果输入行仅为换行符，则不打印 */ 
	if (pos > 0)
		putchar('\n');
}

int exptab(int pos)
{
	int i = 1;
	for (pos; pos < MAXCOL && i <= TABINC; pos++)
		line[pos] = ' ';
	if (pos < MAXCOL)	// 当前行未满 
		return pos;
	else {				// 当前行已满 
		printl(pos);
		return 0;
	}
}

int findblnk(int pos)
{
	while (pos > 0 && line[pos] != ' ')
		pos--;
	if (pos == 0)
		return MAXCOL;
	return pos + 1;
}

int newpos(int pos)
{
	int i, j;
	
	if (pos <= 0 || pos >= MAXCOL)
		return 0;
	else {
		j = 0;
		for (i = pos; i < MAXCOL; i++)
			line[j++] = line[i];
		return j;		// 新的pos 
	}
}
