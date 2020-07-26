/* 2019/3/20 21:43 
 * Function : 统计输入的字符，打印出字符出现频度的直方图 
 */ 
 
#include <stdio.h> 

int main(void) 
{
	int i, c;
	int space = 0, enter = 0, tab = 0;
	int Char[58];
	
	for (i = 1; i <= 58; i++)
		Char[i] = 0;
	
	while ((c = getchar()) != EOF)
	{
		if (c >= 'A' && c <= 'z')
			Char[c - 'A' + 1]++; 
		if (c == ' ')
			space++;
		else if (c == '\n')
			enter++;
		else if (c == '\t')
			tab++; 
	}
	
	for (i = 1; i <= 58; i++)
	{
		printf("%c : ", i + 'A' - 1);
		for (int j = 0; j < Char[i]; j++)	
			putchar('|');
		putchar('\n');
	}
	printf("space : ");
	for (int j = 0; j < space; j++)	
		putchar('|');
	putchar('\n');

	printf("\\n : ");
	for (int j = 0; j < enter; j++)	
		putchar('|');
	putchar('\n');
	
	printf("\\t : ");
	for (int j = 0; j < tab; j++)	
		putchar('|');
	putchar('\n');	
	
	return 0;
}

/* 结果;
=========================
AAAA aaa        BBB
CCCDDDDE
        dacdqer
^Z
A : ||||
B : |||
C : |||
D : ||||
E : |
F :
G :
H :
I :
J :
K :
L :
M :
N :
O :
P :
Q :
R :
S :
T :
U :
V :
W :
X :
Y :
Z :
[ :
\ :
] :
^ :
_ :
` :
a : ||||
b :
c : |
d : ||
e : |
f :
g :
h :
i :
j :
k :
l :
m :
n :
o :
p :
q : |
r : |
s :
t :
u :
v :
w :
x :
y :
z :
space : |
\n : |||
\t : ||

--------------------------------
========================
 */ 


