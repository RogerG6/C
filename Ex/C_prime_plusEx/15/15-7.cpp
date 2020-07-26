# include <stdio.h>
# include <stdbool.h>
# include <string.h>
# include <ctype.h>
char get_first(void);
void change_font(unsigned long * n);
void change_size(unsigned long  * n);
void change_alignment(unsigned long  * n);
void change_bold(unsigned long  * n);
void change_italic(unsigned long  * n);
void change_underline(unsigned long  * n);
void show_style(unsigned long  * n);
void show_menu(void);



int main(void)
{
	unsigned long style = 01 | 0xc00 | 0x20000;
	int ch;
	
	show_style(&style);
	do 
	{
		printf("Enter a choice (q to quit).\n");
		show_menu();
		ch = get_first();
		switch (ch)
		{
			case 'f': change_font(&style); break;
			case 's': change_size(&style); break;
			case 'a': change_alignment(&style); break;
			case 'b': change_bold(&style); break;
			case 'i': change_italic(&style); break;
			case 'u': change_underline(&style); break;
			case 'q': break;
			default: puts("Enter a right choice."); break;
		}	
		show_style(&style);
	} while (ch != 'q');
	
	puts("Bye!");
	
	return 0;
}

char get_first(void)
{
	int c;
	c = getchar();
	while (! isalpha(c))
		c = getchar();
	while (getchar() != '\n')
		continue;
	return tolower(c);
}
void change_font(unsigned long * n)
{
	unsigned long font;
	printf("Enter a font(between 0 to 255) to change: ");
	while (scanf("%d", &font) != 1)
		printf("Please enter a integar between 0 to 255: ");
	*n = font | ((*n) & 0xffffff00);
}

void change_size(unsigned long * n)
{
	unsigned long size;
	
	printf("Enter a size(between 0 to 127) to change: ");
	while (scanf("%d", &size) != 1)
		printf("Please enter a integar between 0 to 127: ");
	*n = (size << 8) | ((*n) & 0xffff80ff);
}

void change_alignment(unsigned long * n)
{
	int c;
	puts("Select alignment:");
	puts("l) left    c) center    r) right");
	c = get_first();
	while (c != 'l' && c != 'c' && c != 'r')
		c = get_first();
	if (c == 'l')
		*n = (*n) & (0xfffe7fff);
	else if (c == 'c')
	{
		*n = (*n) & (0xfffe7fff);
		*n = (01 << 15) | *n;
	}
	else
	{
		*n = (*n) & (0xfffe7fff);
		*n = (02 << 15) | *n;
	}
}

void change_bold(unsigned long * n)
{
	*n = (*n) ^ (01 << 17);
}

void change_italic(unsigned long * n)
{
	*n = (*n) ^ (01 << 18);
}

void change_underline(unsigned long * n)
{
	*n = (*n) ^ (01 << 19);
}

void show_menu(void)
{
	puts("f) change font    s) change size      a) change alignment");
	puts("b) toggle bold    i) toggle italic    u) toggle underline\nq) quit");
}
void show_style(unsigned long * n)
{
	printf("%s %s %s  %c     %c     %c\n", "ID", "SIZE", "ALIGNMENT", 'B', 'I', 'U');
	printf("%d   %d    %s    %s   %s   %s\n", ((*n) & 0xff), ((*n >> 8) & 0x7f), (((*n >> 15) & 03) == 0 ? "left" : (((*n >> 15) & 03) == 1 ? "center" : "right")), 
						(((*n >> 17) & 01) == 1 ? "on" : "off"), (((*n >> 18) & 01) == 1 ? "on" : "off"), (((*n >> 19) & 01) == 1 ? "on" : "off"));
}
