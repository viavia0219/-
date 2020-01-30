#include<stdio.h>
#include<stdlib.h>
//链式栈： 链表+栈
//链表结构体 
struct Node
{
	int data;   //数据域 
	struct Node* next;  //指针域 
};
//创建链表 
struct Node* createList()
{
	struct Node* headNode = (struct Node*)malloc(sizeof(struct Node));
	headNode->next = NULL;
	return headNode;
}
//创建结点
struct Node* createNode(int data)
{
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data = data ;
	newNode->next = NULL ;
	return newNode;
}
//插入结点（头插法）
void insertNodeByHead(struct Node* headNode,int data)
{
	struct Node* newNode = createNode(data);
	newNode->next = headNode->next ;
	headNode->next = newNode ;
}
//删除结点
void deleteNodeByHead(struct Node* headNode)
{
	struct Node* NextNode = headNode->next;
	headNode->next = NextNode->next;
 } 
//打印结点
void printfList(struct Node* headNode)
{
	struct Node* pMove = headNode->next;
	while(pMove)
	{
		printf("%d\t",pMove->data);
		pMove = pMove->next;
	}
	printf("\n");
 } 
//抽象栈结构的结构体
//结构体：抽象事物的属性

struct stack
{
	int stackSize;   //栈的大小
	struct Node* stackTop;  //栈顶指针： 表示整个链表内存（充当链表表头）   
} ;
//创建栈   - - -> 描述事物的最初状态 
struct stack* createStack()
{
  struct stack* mystack = (struct stack*)malloc(sizeof(struct stack));
  mystack->stackSize = 0;
  mystack->stackTop = createList();
  return mystack;	
} 
void push(struct stack* mystack,int data)
{
	insertNodeByHead(mystack->stackTop,data);
	mystack->stackSize ++;
}
int getTop(struct stack* mystack)
{
	if(mystack == 0)
     return -1;
	else
	return mystack->stackTop->next->data;
}
void pop(struct stack* mystack)
{   
	deleteNodeByHead(mystack->stackTop);
	mystack->stackSize--;
     
}
int empty(struct stack* mystack)
{
	if(mystack->stackSize = 0)
	return 1;
	else
	return 0;
}




int main()
{
	struct stack* mystack = createStack();
	push(mystack,1);
	push(mystack,2);
	push(mystack,3);
	while(!empty(mystack))
    {
    	printf("%d\t",getTop(mystack));
    	pop(mystack);
	}
	printf("\n");
	system("pause");
	return 0;
 } 
