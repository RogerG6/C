/* tree.c -- tree support functions */
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "17-8tree.h"

/* local data type */
typedef struct pair {
    Trnode * parent;
    Trnode * child;
} Pair;

typedef struct kindpair {
	Petkind * parent;
	Petkind * child;
}Kindpair;

/* protototypes for local functions */
static Trnode * MakeNode(const char * pname, const char * pkind);
static bool ToLeft(const char * i1, const char * i2);
static bool ToRight(const char * i1, const char * i2);
static void AddNode (Trnode * new_node, Trnode * root);
static void InOrder(const Trnode * root);
static Pair SeekItem(const char * pi, const Tree * ptree);
static void DeleteNode(Trnode **ptr);
static void DeleteAllNodes(Trnode * ptr);
static void InitializePtree(Ptree * ptree);
static bool AddKind(const char * pi,Ptree * ptree);
static Kindpair SeekPet(const char * pi, const Ptree * ptree);
static void showpetname(const char * st);
static void showpetkind(const Ptree * ptree);
static void Doall(const Ptree * ptree);
static void Order(const Petkind * proot);
static Petkind *  MakeKindNode(const char * kname);
/* function definitions */
void InitializeTree(Tree * ptree)
{
    ptree->root = NULL;
    ptree->size = 0;
}

bool TreeIsEmpty(const Tree * ptree)
{
    if (ptree->root == NULL)
        return true;
    else
        return false;
}

bool TreeIsFull(const Tree * ptree)
{
    if (ptree->size == MAXITEMS)
        return true;
    else
        return false;
}

int TreeItemCount(const Tree * ptree)
{
    return ptree->size;
}

void PrintPet(const char * pi, const Tree * ptree)
{
	Pair pnode;
	pnode = SeekItem(pi, ptree);
	showpetname(pnode.child->petname);
	showpetkind(&(pnode.child->petkind));
}

bool AddItem(const char * pi, const char * kname, Tree * ptree)
{
    Trnode * new_node;
    Pair look;
    Kindpair find;
    look = SeekItem(pi, ptree);
    if  (TreeIsFull(ptree))
    {
        fprintf(stderr,"Tree is full\n");
        return false;             /* early return           */
    }
    if (look.child != NULL)
    {
    	find = SeekPet(kname, &(look.child->petkind));
		if (find.child == NULL)
        	             /* early return           */
        	AddKind(kname, &(look.child->petkind));
        return false;
    }
    new_node = MakeNode(pi, kname);      /* points to new node     */
    if (new_node == NULL)
    {
        fprintf(stderr, "Couldn't create node\n");
        return false;             /* early return           */
    }
    /* succeeded in creating a new node */
    ptree->size++;
    
    if (ptree->root == NULL)      /* case 1: tree is empty  */
        ptree->root = new_node;   /* new node is tree root  */
    else                          /* case 2: not empty      */
        AddNode(new_node,ptree->root); /* add node to tree  */
    
    return true;                  /* successful return      */
}

bool InTree(const char * pi, const Tree * ptree)
{
    return (SeekItem(pi, ptree).child == NULL) ? false : true;
}

bool DeleteItem(const char * pi, Tree * ptree)
{
    Pair look;
    
    look = SeekItem(pi, ptree);
    if (look.child == NULL)
        return false;
    
    if (look.parent == NULL)      /* delete root item       */
        DeleteNode(&ptree->root);
    else if (look.parent->left == look.child)
        DeleteNode(&look.parent->left);
    else
        DeleteNode(&look.parent->right);
    ptree->size--;
    
    return true;
}

void Traverse (const Tree * ptree)
{
    
    if (ptree != NULL)
        InOrder(ptree->root);
}

void DeleteAll(Tree * ptree)
{
    if (ptree != NULL)
        DeleteAllNodes(ptree->root);
    ptree->root = NULL;
    ptree->size = 0;
}


/* local functions */
static void InOrder(const Trnode * root)
{
    if (root != NULL)
    {
       
        showpetname(root->petname);
        showpetkind(&(root->petkind));
        InOrder(root->left);
         InOrder(root->right);
    }
}

static void DeleteAllNodes(Trnode * root)
{
    Trnode * pright;
    
    if (root != NULL)
    {
        pright = root->right;
        DeleteAllNodes(root->left);
        free(root);
        DeleteAllNodes(pright);
    }
}

static void AddNode (Trnode * new_node, Trnode * root)
{
    if (ToLeft(new_node->petname, root->petname))
    {
        if (root->left == NULL)      /* empty subtree       */
            root->left = new_node;   /* so add node here    */
        else
            AddNode(new_node, root->left);/* else process subtree*/
    }
    else if (ToRight(new_node->petname, root->petname))
    {
        if (root->right == NULL)
            root->right = new_node;
        else
            AddNode(new_node, root->right);
    }
    else                         /* should be no duplicates */
    {
        fprintf(stderr,"location error in AddNode()\n");
        exit(1);
    }
}

static void AddKindNode (Petkind * new_node, Petkind * root)
{
    if (ToLeft(new_node->kindname, root->kindname))
    {
        if (root->left == NULL)      /* empty subtree       */
            root->left = new_node;   /* so add node here    */
        else
            AddKindNode(new_node, root->left);/* else process subtree*/
    }
    if (ToRight(new_node->kindname, root->kindname))
    {
        if (root->right == NULL)
            root->right = new_node;
        else
            AddKindNode(new_node, root->right);
    }
   
}

static bool ToLeft(const char * i1, const char * i2)
{
    int comp1;
    
    if ((comp1 = strcmp(i1, i2)) < 0)
        return true;
    else
        return false;
}

static bool ToRight(const char * i1, const char * i2)
{
    int comp1;
    
    if ((comp1 = strcmp(i1, i2)) > 0)
        return true;
    else
        return false;
}

static Trnode * MakeNode(const char * pname, const char * pkind)
{
    Trnode * new_node;
    
    new_node = (Trnode *) malloc(sizeof(Trnode));
    if (new_node != NULL)
    {
        strcpy(new_node->petname, pname);
        InitializePtree(&(new_node->petkind));
        AddKind(pkind, &(new_node->petkind));
        new_node->left = NULL;
        new_node->right = NULL;
    }
    
    return new_node;
}

static Pair SeekItem(const char * pi, const Tree * ptree)
{
    Pair look;
    look.parent = NULL;
    look.child = ptree->root;
    
    if (look.child == NULL)
        return look;                        /* early return   */
    
    while (look.child != NULL)
    {
        if (ToLeft(pi, look.child->petname))
        {
            look.parent = look.child;
            look.child = look.child->left;
        }
        else if (ToRight(pi, look.child->petname))
        {
            look.parent = look.child;
            look.child = look.child->right;
        }
        else       /* must be same if not to left or right    */
            break; /* look.child is address of node with item */
    }
    
    return look;                       /* successful return   */
}

static void DeleteNode(Trnode **ptr)
/* ptr is address of parent member pointing to target node  */
{
    Trnode * temp;
    
    if ( (*ptr)->left == NULL)
    {
        temp = *ptr;
        *ptr = (*ptr)->right;
        free(temp);
    }
    else if ( (*ptr)->right == NULL)
    {
        temp = *ptr;
        *ptr = (*ptr)->left;
        free(temp);
    }
    else    /* deleted node has two children */
    {
        /* find where to reattach right subtree */
        for (temp = (*ptr)->left; temp->right != NULL;
             temp = temp->right)
            continue;
        temp->right = (*ptr)->right;
        temp = *ptr;
        *ptr =(*ptr)->left;
        free(temp); 
    }
}

//-------------------------------
static void InitializePtree(Ptree * ptree)
{
    ptree->proot = NULL;
    ptree->psize = 0;
}

static bool AddKind(const char * pi,Ptree * ptree)
{
    Petkind * new_node;
    Kindpair  look;
    look = SeekPet(pi, ptree);
    

    if (look.child != NULL)
    {
        return false;             /* early return           */
    }
    new_node = MakeKindNode(pi);      /* points to new node     */
    if (new_node == NULL)
    {
        fprintf(stderr, "Couldn't create node\n");
        return false;             /* early return           */
    }
    /* succeeded in creating a new node */
    ptree->psize++;
    
    if (ptree->proot == NULL)      /* case 1: tree is empty  */
        ptree->proot = new_node;   /* new node is tree root  */
    else                          /* case 2: not empty      */
        AddKindNode(new_node,ptree->proot); /* add node to tree  */
    
    return true;                  /* successful return      */
}

static Petkind *  MakeKindNode(const char * kname)
{
	Petkind * pnode;
	pnode = (Petkind *)malloc(sizeof(Petkind));
	
	if (pnode != NULL)
	{
		strcpy(pnode->kindname, kname);
		pnode->left = NULL;
		pnode->right = NULL;
	}
}

static Kindpair SeekPet(const char * pi, const Ptree * ptree)
{
    Kindpair look;
    look.parent = NULL;
    look.child = ptree->proot;
    
    if (look.child == NULL)
        return look;                        /* early return   */
    
    while (look.child != NULL)
    {
        if (ToLeft(pi, look.child->kindname))
        {
            look.parent = look.child;
            look.child = look.child->left;
        }
        else if (ToRight(pi, look.child->kindname))
        {
            look.parent = look.child;
            look.child = look.child->right;
        }
        else       /* must be same if not to left or right    */
            break; /* look.child is address of node with item */
    }
    
    return look;                       /* successful return   */
}

static void showpetname(const char * st)
{
	printf("%-s:\n", st);
}

static void showpetkind(const Ptree * ptree)
{
	Doall(ptree);
}

static void Doall(const Ptree * ptree)
{
	if (ptree != NULL)
		Order(ptree->proot);
}

static void Order(const Petkind * proot)
{
	if (proot !=NULL)
	{
		Order(proot->left);
		printf("%10s\n", proot->kindname);
		Order(proot->right);
	}	
}


