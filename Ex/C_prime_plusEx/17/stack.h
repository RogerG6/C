# include <stdbool.h>
# define SIZE 45

typedef struct node {
	char ch;
	struct node * next;
	struct node * pre;
}Node;

struct stack {
	Node * head;
	Node * end;
	int num;
};
typedef struct stack Sta;

void InitializeSt(Sta * pst);  //��ʼ��
bool StackIsEmpty(Sta * pst);  
bool StackIsFull(Sta * pst);
int StackCharCount(Sta * pst);
bool AddChar(char ch, Sta * pst);   //����һ��Ԫ��
void ShowChar(Sta * pst);
//void EmptyStack(Sta * pst);




