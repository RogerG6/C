/* Date：2020/3/7 
 * 5-3：用指针的方式实现第2章中的函数strcat。函数strcat(s, t)将t指向的字符串复制到s指向的字符串的尾部
 */ 

#include <stdio.h> 

void __strcat(char *s, char *t)
{
	while (*s)
		s++;
	while (*s++ = *t++)
		;
}

int main(void)
{
	char a[100] = "hello";
	char *b = "world!!!";
	
	__strcat(a, b);
	
	printf("String a: %s\n", a);
	
	return 0;
}


/*
String a: helloworld!!!

--------------------------------
Process exited after 0.3547 seconds with return value 0
请按任意键继续. . .


*/ 
