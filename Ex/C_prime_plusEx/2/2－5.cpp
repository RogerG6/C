# include <stdio.h>

void br();
void ic();

int main(void) 
{
	br();
	printf(", ");
	ic();
	ic();
	br();
	
	return 0;
}

void br(void)
{
	printf("Brazil, Russia");
}

void ic(void)
{
	printf("India, China\n");
}
