#include<stdio.h>
#include<stdlib.h>
//��ʽջ�� ����+ջ
//����ṹ�� 
struct Node
{
	int data;   //������ 
	struct Node* next;  //ָ���� 
};
//�������� 
struct Node* createList()
{
	struct Node* headNode = (struct Node*)malloc(sizeof(struct Node));
	headNode->next = NULL;
	return headNode;
}
//�������
struct Node* createNode(int data)
{
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data = data ;
	newNode->next = NULL ;
	return newNode;
}
//�����㣨ͷ�巨��
void insertNodeByHead(struct Node* headNode,int data)
{
	struct Node* newNode = createNode(data);
	newNode->next = headNode->next ;
	headNode->next = newNode ;
}
//ɾ�����
void deleteNodeByHead(struct Node* headNode)
{
	struct Node* NextNode = headNode->next;
	headNode->next = NextNode->next;
 } 
//��ӡ���
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
//����ջ�ṹ�Ľṹ��
//�ṹ�壺�������������

struct stack
{
	int stackSize;   //ջ�Ĵ�С
	struct Node* stackTop;  //ջ��ָ�룺 ��ʾ���������ڴ棨�䵱�����ͷ��   
} ;
//����ջ   - - -> ������������״̬ 
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
