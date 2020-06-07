/* Date：2020/4/4
 * Author: rogerg6*
 * Func: 计算器小程序
 * 			采用EBNF语法：
 * 			+-和* /连续运算可以通过while循环解决
 *			+- * / 的混合运算，可以通过函数来解决
 *			() 运算可以通过递归来解决
 */

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

#define RET 0.
int token;

void calc(void);
double add_sub(void);
double mul_div(void);
double get_fact(void);
void match(int expectedToken);
char get_printable_char(void);
void error(void);

int main(void)
{
	printf("*********************calculator*********************\nUsage:\
		q to quit!\n");
	
	do
		calc();
	while (token != 'q');
	
	return 0;
}

void calc(void)
{
	double result;
	
	if ((token = getchar()) == 'q')
		;
	
	result = add_sub();
	if (token == '\n')
		printf("result = %lf\n", result);
	else
		error();
}

double add_sub(void)
{
	double t;
	t = mul_div();

	while (token == '+' || token == '-')
		switch(token) {
			case '+':
				match('+');		// 获取下一个token
				t += mul_div();
				break;
			case '-':
				match('-');
				t -= mul_div();
				break;
		}
	return t;
}

double mul_div(void)
{
	double t;

	t = get_fact();
	while (token == '*' || token == '/')
		switch(token) {
			case '*':
				match('*');
				t *= get_fact();
				break;
			case '/':
				match('/');
				t /= get_fact();
				break;
		}
	//printf("mul: t = %lf\n", t);
	return t;	
}

double get_fact(void)
{
	double t;
	
	if (isdigit(token) || token == '-')	{    // 数字
		ungetc(token, stdin);
		scanf("%lf", &t);
		token = get_printable_char();
	}		
	else if (token == '('){				// 左括号
		match('(');
		t = add_sub();
		match(')');
	}				
	else							// 错误
		error();

	return t;

}

void match(int expectedToken)
{
	if (token == expectedToken)		// 匹配
		token = get_printable_char();
	else
		error();
}

char get_printable_char(void)
{
	int c;
	while (isblank(c = getchar()))	// 是否为' ' or '\t'
		;
	return c;
}

void error(void)
{
	printf("error!\n");
	exit(-1);
}