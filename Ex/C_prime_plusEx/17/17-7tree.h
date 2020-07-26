# define _TREE_H_
# include <stdbool.h>
# define LEN 50


typedef struct trnode {
	char word[LEN];
	int ct;
	struct trnode * left;
	struct trnode * right;
}Trnode;

typedef struct tree {
	Trnode * root;
	int size;
}Tree;

void InitializeTree(Tree * ptree);
bool TreeIsEmpty(Tree * ptree);
bool TreeIsFull(Tree * ptree);
bool AddItem(char * pi, Tree * ptree);
void EmptyTree(Tree * ptree);
void Traverse(Tree * ptree, void (*pfun)(Trnode * pnode));
void show_word_times(Tree * ptree, void (*pfun)(Trnode * pnode)) ;
void print_times(Tree * ptree, char * st);
