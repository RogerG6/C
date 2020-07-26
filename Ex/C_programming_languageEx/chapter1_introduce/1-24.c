/* Date��2020/3/24
 * 1-24����дһ�����򣬲���C�����еĻ����﷨������Բ���š��������Լ������Ų���Եȡ�Ҫ��ȷ��������(���������š�˫����)
 *	  ת���ַ�������ע�͡�(���������Ѹó����д��ͨ�ó����ѶȻ�Ƚϴ�)
 */
#include <stdio.h>

int brace, brack, paren;

void in_quote(int c);
void search(int c);
void in_comment(void);

int main(void)
{
	int c;
	int d;
	
	printf("%d %d %d\n", brace, brack, paren);
	
	while ((c = getchar()) != EOF) {
		if (c == '/') {
			if ((c = getchar()) == '*')
				in_comment();
			else
				search(c);
		}
		else if (c == '\'' || c == '"')
			in_quote(c);
		else
			search(c);
			
		if (brace < 0) {
			printf("Unbalanced braces\n");
			brace = 0;
		} else if (brack < 0) {
			printf("Unbalanced bracks\n");
			brack = 0;
		} else if (paren < 0) {
			printf("Unbalanced parens\n");
			paren = 0;
		}
	}
	
	if (brace > 0) {
		printf("Unbalanced braces\n");
		brace = 0;
	} else if (brack > 0) {
		printf("Unbalanced bracks\n");
		brack = 0;
	} else if (paren > 0) {
		printf("Unbalanced parens\n");
		paren = 0;
	}
	return 0;
}

void search(int c)
{
	if (c == '{')
		brace++;
	else if (c == '}')
		brace--;
	else if (c == '[')
		brack++;
	else if (c == ']')
		brack--;
	else if (c == '(')
		paren++;
	else if (c == ')')
		paren--;
}

void in_comment(void)
{
	int c = getchar();
	int d = getchar();
	
	while (c != '*' || d != '/') {
		c = d;
		d = getchar();
	}
}

void in_quote(int c)
{
	int d;
	while ((d = getchar()) != c)
		if (d == '\\')
			getchar();
}
