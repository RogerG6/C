#define NUMBER 1
#define MAXLEN 1000

// 存放运算数
double num;

// 输入的表达式
char input[MAXLEN]; 
int ip;


// 运算符栈
int symbol[MAXLEN];
int syp;

// 后缀表达式栈
char suffix[MAXLEN];
int sufp;
