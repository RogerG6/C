# include <stdio.h>
int main(void)
{
/*	char ch[10];
	int i ;
	for(i = 0; i < 10; i++)
	{
		scanf(" %c", &ch[i]);  //�ÿո��getchar() �����ַ���Ļس���ո� 
		//getchar();
	}
	for(i = 0; i < 10; i++)
	{
		printf("%c", ch[9-i]);
	}*/
	int i = -1;
    char input[256];

    printf("Please input the string:");

    do
    {
        i++;
        scanf("%c", &input[i]);
    } while (input[i] != '\n');

    for (size_t j = i; j > 0; j--)
    {
        printf("%c", input[j - 1]);
    }
    printf("\n");


	
	return 0;
}
