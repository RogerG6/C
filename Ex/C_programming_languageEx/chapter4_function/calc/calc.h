#include <stdio.h>
#include <ctype.h>

#define NUMBER '0'
#define abs(x) (x > 0 ? (x) : (-x))

void ungetch(int c);
int getch(void);
int getop(char s[]);
double pop(void);
void push(double x);
double atof(char s[]);



