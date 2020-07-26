# ifndef LIST_H_
# define LIST_H_
# include <stdbool.h> 
# define MAXSIZE 100
# define TSIZE 45

struct film {
	char title[TSIZE];
	int rating;
};

typedef struct film Item;


typedef struct list{
	Item entries[MAXSIZE];
	int items;
}List;

void InitializeList(List * pl);
bool ListIsEmpty(List * pl);
bool ListIsFull(List * pl);
unsigned int ListItemCount(List * pl);
bool AddItem(Item item, List * pl);
void Traverse(List * pl, void (*pfun)(Item item));
void EmptyTheList(List * pl);

#endif
