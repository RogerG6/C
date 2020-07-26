/* Date：2020/3/7 
 * 5-7：重写函数readlines，将输入的文本行存储到由main函数提供的一个数组中，而不是存储到alloc分配的空间中。
 *      该函数的运行速度比改写前快多少？
 */ 
 
#include <stdio.h>
#include <string.h>

#define MAXLINES 5000	//最多输入行 
#define MAXLEN   1000	//一行最多输入长度 
#define BUFSIZE  10000


char *lineptr[MAXLINES];
char str[BUFSIZE];		/* 存放输入的文本行 */ 
char *sp = str; 

int readlines(char *lineptr[], int maxlines);
int getline(char *line, int maxlen);
void qsort(char *v[], int left, int right);
void swap(char *v[], int i, int j);
void writelines(char *lineptr[], int lines);
char * alloc(int n);
void afree(char *p);

int main(void)
{
	int nlines, i;
	
	if ((nlines = readlines(lineptr, MAXLINES)) >= 0)
	{
		printf("nlines = %d\n", nlines);
		qsort(lineptr, 0, nlines - 1);
		writelines(lineptr, nlines);
		
		//afree(lineptr[0]);
			
		return 0;
	}
	else
	{
		printf("error: input too big to sort\n");
		return 1;
	}
	
	return 0;
}

int readlines(char *lineptr[], int maxlines)
{
	int nlines = 0, len;
	char *line, *p;
	
	while ((len = getline(line, MAXLEN))> 0) 
	{
		if (nlines > maxlines || (str + BUFSIZE - sp) < len)
			return -1;
		else
		{
			line[len - 1] = '\0';
			strcpy(sp, line);
			lineptr[nlines++] = sp;
			sp += len;
		}
		//printf("nlines = %d\n", nlines);
	}
	return nlines;
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


void qsort(char *v[], int left, int right)
{
	int i, last;
	
	if (left >= right)
		return;
	swap(v, left, (left + right) / 2);
	
	last = left;
	for (i = left + 1; i <= right; i++)
		if (strcmp(v[i], v[left]) < 0)
			swap(v, ++last, i);
	
	swap(v, left, last);
	qsort(v, left, last - 1);
	qsort(v, last + 1, right);
}

void swap(char *v[], int i, int j)
{
	char *t;
	t = v[i];
	v[i] = v[j];
	v[j] = t;
}

void writelines(char *lineptr[], int lines)
{
	int i;
	for (i = 0; i < lines; i++)
		printf("%s\n", lineptr[i]);
}


char buf[BUFSIZE];
char *bufp = buf; 

char * alloc(int n)
{
	if (buf + BUFSIZE - bufp >= n)
	{
		bufp += n;
		return bufp - n;
	}
	else
	{
		printf("error: no more memory\n");
		return NULL;
	}
}

void afree(char *p)
{
	if (p >= buf && p < buf + BUFSIZE)
		bufp = p;
	else
		printf("error: it's a NULL pointer\n");
}
