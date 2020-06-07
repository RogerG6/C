#include <stdio.h>
#include "calc.h"
#include <ctype.h>

void sym_push(int c);
int sym_pop(void);
void suffix_push(int c);

// 获得优先级
int get_pri(int c)
{
	switch (c) {
		case '+': return 1; break;
		case '-': return 1; break;
		case '*': return 2; break;
		case '/': return 2; break;
		default : return 0; break;
	}
}

// 将数字copy到后缀表达式字符串中
void copy_digit(void)
{
	while(isdigit(input[ip]) || input[ip] == '.') {
		suffix_push(input[ip++]);
	}
	suffix_push(' ');
}

// 将中缀表达式 转换成 后缀表达式
void infix_to_suffix(void)
{
	int c, d;
	ip = 0;
	syp = 0;
	sufp = 0;

	while ((c = input[ip]) != '\n')
		if (isdigit(c)){		// 数字
			copy_digit();
				
		}
		else if (c == '+' || c == '-' || c == '*' || c == '/') {	// 运算符
			if (c == '-' && isdigit(input[ip + 1])){				// 处理负数
				suffix_push('-');
				ip++;
				copy_digit();
				continue;
			}
			if (syp > 0 && (get_pri(symbol[syp - 1]) >= get_pri(c))){	// 比较当前运算符与栈顶的优先级
				suffix_push(sym_pop())	;
				suffix_push(' ');
			}
			sym_push(c);
			ip++;
		}
		else if (c == '(')			// 左括号
			sym_push(c), ip++;
		else if (c == ')'){			// 右括号
			while ((d = sym_pop()) != '('){
				suffix_push(d);
				suffix_push(' ');
			}
			ip++;
		}
		else
			ip++;
	while (syp > 0) {			// 弹出栈中所有的运算符
		suffix_push(sym_pop());
		suffix_push(' ');
	}
	suffix_push('\n');
	suffix_push('\0');
}
