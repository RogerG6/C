/* Date��2020/3/24 
 * 1-22����дһ�����򣬰ѽϳ��������С��ۡ��ɶ�һЩ�����л���У����е�λ���������еĵ�n��֮ǰ�����һ���ǿո��֮��
 *	     Ҫ��֤�����ܹ����ܵش��������кܳ��Լ���ָ������ǰû�пո���Ʊ������� 
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
			printl(pos);		//��ӡ��ǰ�� 
			pos = 0;			
		} else if (c == '\t') {
			pos = exptab(pos);	// ��չTABΪ4���ո� 
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
		
	/* ��������н�Ϊ���з����򲻴�ӡ */ 
	if (pos > 0)
		putchar('\n');
}

int exptab(int pos)
{
	int i = 1;
	for (pos; pos < MAXCOL && i <= TABINC; pos++)
		line[pos] = ' ';
	if (pos < MAXCOL)	// ��ǰ��δ�� 
		return pos;
	else {				// ��ǰ������ 
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
		return j;		// �µ�pos 
	}
}
