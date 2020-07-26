# include <stdio.h>
int main(void)
{
	int i;
	char a[26];
	
	for(i = 0; i < 26; i++)
	{
		scanf("%s", a);
		printf("%s ", a);
	}
	
	return 0;
}

/*在Dev－C++5.10中运行结果为：
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
a b c d e f g h i j k l m n o p q r s t u v w x y z
a b c d e f g h i j k l m n o p q r s t u v w x y z
--------------------------------
Process exited after 25.52 seconds with return value 0
请按任意键继续. . 
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
*/
