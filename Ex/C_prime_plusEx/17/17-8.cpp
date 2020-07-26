/* petclub.c -- use a binary search tree */
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "17-8.c"

char menu(void);
void addpet(Tree * pt);
void droppet(Tree * pt);
void showpets(const Tree * pt);
void findpet(const Tree * pt);

void uppercase(char * str);
char * s_gets(char * st, int n);

int main(void)
{
    Tree pets;
    char choice;
    
    InitializeTree(&pets);
    while ((choice = menu()) != 'q')
    {
        switch (choice)
        {
            case 'a' :  addpet(&pets);
                break;
            case 'l' :  showpets(&pets);
                break;
            case 'f' :  findpet(&pets);
                break;
            case 'n' :  printf("%d pets in club\n",
                               TreeItemCount(&pets));
                break;
            case 'd' :  
                break;
            default  :  puts("Switching error");
        }
    }
    DeleteAll(&pets);
    puts("Bye.");
    
    return 0;
}

char menu(void)
{
    int ch;
    
    puts("Nerfville Pet Club Membership Program");
    puts("Enter the letter corresponding to your choice:");
    puts("a) add a pet          l) show list of pets");
    puts("n) number of pets     f) find & show pets");
    puts("d) delete a pet       q) quit");
    while ((ch = getchar()) != EOF)
    {
        while (getchar() != '\n')  /* discard rest of line */
            continue;
        ch = tolower(ch);
        if (strchr("alrfndq",ch) == NULL)
            puts("Please enter an a, l, f, n, d, or q:");
        else
            break;
    }
    if (ch == EOF)       /* make EOF cause program to quit */
        ch = 'q';
    
    return ch;
}

void addpet(Tree * pt)
{
    char petname[SLEN];
    char petkind[SLEN];
    
    if (TreeIsFull(pt))
        puts("No room in the club!");
    else
    {
        puts("Please enter name of pet:");
        s_gets(petname,SLEN);
        puts("Please enter pet kind:");
        s_gets(petkind,SLEN);
        uppercase(petname);
        uppercase(petkind);
        AddItem(petname, petkind, pt);
    }
}

void showpets(const Tree * pt)
{
    if (TreeIsEmpty(pt))
        puts("No entries!");
    else
        Traverse(pt);
    putchar('\n');
}


void findpet(const Tree * pt)
{
    char petname[SLEN];
    char petkind[SLEN];
    
    if (TreeIsEmpty(pt))
    {
        puts("No entries!");
        return;     /* quit function if tree is empty */
    }
    
    puts("Please enter name of pet you wish to find:");
    s_gets(petname, SLEN);

    uppercase(petname);
    
    if (InTree(petname, pt))
        PrintPet(petname, pt);
    else
        printf("is not a member.\n");
}



void uppercase(char * str)
{
    while (*str)
    {
        *str = toupper(*str);
        str++;
    }
}
char * s_gets(char * st, int n)
{
    char * ret_val;
    char * find;
    
    ret_val = fgets(st, n, stdin);
    if (ret_val)
    {
        find = strchr(st, '\n');   // look for newline
        if (find)                  // if the address is not NULL,
            *find = '\0';          // place a null character there
        else
            while (getchar() != '\n')
                continue;          // dispose of rest of line
    }
    return ret_val;
}

