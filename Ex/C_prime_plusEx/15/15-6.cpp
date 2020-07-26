# include <stdio.h>
# include <stdbool.h>
# include <string.h>
# include <ctype.h>
char get_first(void);
void change_font(struct word * ps);
void change_size(struct word * ps);
void change_alignment(struct word * ps);
void change_bold(struct word * ps);
void change_italic(struct word * ps);
void change_underline(struct word * ps);
void show_style(struct word * ps);
void show_menu(void);

const char * choice = "fsabiu";
struct word {
	unsigned int font : 8;
	unsigned int size : 7;
	unsigned int alignment : 2;
	bool bold : 1;
	bool italic :  1;
	bool underline : 1;
};
int main(void)
{
	struct word style = {1, 12, 0, false, false, false};	
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
	return c;
}
void change_font(struct word * ps)
{
	int font;
	printf("Enter a font(between 0 to 255) to change: ");
	while (scanf("%d", &font) != 1)
		printf("Please enter a integar between 0 to 255: ");
	ps->font = font ;
}

void change_size(struct word * ps)
{
	int size;
	
	printf("Enter a size(between 0 to 127) to change: ");
	while (scanf("%d", &size) != 1)
		printf("Please enter a integar between 0 to 127: ");
	ps->size = size;
}

void change_alignment(struct word * ps)
{
	int c;
	puts("Select alignment:");
	puts("l) left    c) center    r) right");
	c = get_first();
	while (c != 'l' && c != 'c' && c != 'r')
		c = get_first();
	if (c == 'l')
		ps->alignment = 0;
	else if (c == 'c')
		ps->alignment = 1;
	else
		ps->alignment = 2;
}

void change_bold(struct word * ps)
{
	ps->bold = ! (ps->bold);
}

void change_italic(struct word * ps)
{
	ps->italic = ! (ps->italic);
}

void change_underline(struct word * ps)
{
	ps->underline = ! (ps->underline);
}

void show_menu(void)
{
	puts("f) change font	s) change size      a) change alignment");
	puts("b) toggle bold    i) toggle italic    u) toggle underline\nq) quit");
}
void show_style(struct word * ps)
{
	printf("%s %s %s  %c     %c     %c\n", "ID", "SIZE", "ALIGNMENT", 'B', 'I', 'U');
	printf("%d   %d    %s    %s   %s   %s\n", ps->font, ps->size, (ps->alignment == 0 ? "left" : (ps->alignment == 1 ? "mid" : "right")), 
						(ps->bold == true ? "on" : "off"), (ps->italic == true ? "on" : "off"), (ps->underline == true ? "on" : "off"));
}
