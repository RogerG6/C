/* Date��2020/3/23
 * 1-11����׼����β��Ե��ʼ���������������д���ĳ�ִ�����ôʲô������������ܷ����������
 */ 
 
/* ����p14ҳ�ĵ��ʼ������� */ 
#include <stdio.h>
#define IN 1
#define OUT 0
int main(void)
{
	int nl, nw, nc, c;
	int state = OUT;
	
	nl = nw = nc = 0;
	while ((c = getchar()) != EOF){
		nc++;
		if (c == '\n')
			nl++;
		if (c == ' ' || c == '\n' || c == '\t')
			state = OUT;
		else if (state == OUT){
			state = IN;
			nw++;
		}
	}
	printf("nl = %d, nw = %d, nc = %d\n", nl, nw, nc);
	return 0;	
} 

/* ��Щ����߽���������������������ڷ��ֵ��ʼ�������Ĵ���
 *		û������
 *		û�е���(ֻ�л��з�) 
 *		û�е���(ֻ�пո��Ʊ�������з�)
 *		ÿ�����ʸ�ռһ�е����
 *		���ʳ������ļ����׵����
 *		���ʳ�����һ���ո�֮������
 */ 

