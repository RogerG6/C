# include <stdio.h>
char * mystrncpy(char * st1, char * st2, int n);

int main(void)
{
	char * str1;
	char * str2;
	int n;
	do
	{
		puts("Enter string 2:");
		gets(str2);
		puts("Enter the length u want to cpoy:");
		scanf("%d", &n);
		while (getchar() != '\n')
			;
			
		str2 = mystrncpy(str1, str2, n);
		puts(str1);
		puts(str2);
		
		puts("Press enter to continue, q to quit!");	
	}while (getchar () != 'q');
	
	return 0;
}

char * mystrncpy(char * st1, char * st2, int n)
{
	int ct = 1;
	while (ct <= n && *st2 != '\0')
	{
		*st1 = *st2;
		st1++;
		st2++;
		ct++;
	}
//	if (ct < n)
		*st1 = '\0';
	return st2;
}

/*
// practice 7
char *mystrncpy(char *s1, char *s2, int n)
{
    int s1_length = strlen(s1);
    int s2_length = strlen(s2);
    int copy_length = (s2_length >= n ? n : s2_length);

    for (size_t i = 0; i < copy_length; i++)
    {
        s1[s1_length + i] = s2[i];
    }

    if (s2_length < n)
    {
        s1[s1_length + s2_length] = '\0';
    }

    return s1;
}
void p11_7(void)
{
    char string1[256];
    char string2[256];
    int string1_length = 0;
    int string2_length = 0;

    while (1) // 一直循环输入吧，也可以添加一个退出条件
    {
        printf("Enter the first string:");
        gets_s(string1, 256);

        printf("Enter the second string:");
        gets_s(string2, 256);

        string1_length = strlen(string1);
        string2_length = strlen(string2);

        printf("The first original string: ");
        puts(string1);
        mystrncpy(string1, string2, (256 - string1_length));
        printf("After mystrncpy, ths first string: ");
        puts(string1);
    }

    return;
}

*/
