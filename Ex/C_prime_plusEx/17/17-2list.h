# ifndef LIST_H_
# define LIST_H_
# include <stdbool.h> 

# define TSIZE 45

struct film {
	char title[TSIZE];
	int rating;
};

typedef struct film Item;

typedef struct node {
	Item item;
	struct node * next;
}Node;

typedef struct list{
	Node * head;
	Node * end;
}List;

void InitializeList(List * lb);
bool ListIsEmpty(List * lb);
bool ListIsFull(List * lb);
unsigned int ListItemCount(List * lb);
bool AddItem(Item item, List * lb);
void Traverse(List * lb, void (*pfun)(Item item));
void EmptyTheList(List * lb);

#endif
