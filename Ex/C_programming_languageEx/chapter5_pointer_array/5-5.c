/* Date：2020/3/7 
 * 5-5：实现库函数strncpy, strncat, strncmp，它们最多对参数字符串中的前n个字符进行操作。例如：函数strncpy(s, t, n)
 *      将t中最多前n个字符复制到s中，更详细的说明请参见附录B
 */ 
 
#include <stdio.h>
#include <string.h>

void __strncpy(char *s, char *t, int n) 
{
	while (*t && n-- > 0)
		*s++ = *t++;
	
	/* 如果t中不足n个元素，则在s末尾填充'\0' */ 
	while (n-- > 0)
		*s++ = '\0';
}

void __strncat(char *s, char *t, int n)
{
	__strncpy(s + strlen(s), t, n);
}

/* 前n个字符比较 ，返回字符间间距 
 * s < t : 负数 
 * s > t : 正数 
 * s = t : 0 
 */ 
int __strncmp(char *s, char *t, int n)
{
	for (; *s == *t; s++, t++)
		/* 到达s或t的末尾 或 比较完n个字符，则返回 */ 
		if (*s == '\0' || --n <= 0)
			return 0;
	return *s - *t;
}

int main(void)
{
	char s[100];
	char *cpy = "hello world!";
	char *cat = "I am rogerg6.";
	char *cmp = "helk.";
	int len;
	
	__strncpy(s, cpy, 12);
	printf("string s: %s\n", s);
	
	__strncat(s, cat, 15);
	printf("string s: %s\n", s);

	printf("s 和 cmp 前4个字符是%s一样的\n字符间间距：%d\n", (len = __strncmp(s, cmp, 4)) ? "不" : "", len);

	
	
	return 0;
}
