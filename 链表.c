#include <stdio.h>
#include <stdlib.h>
/*
动态创建一个链表：  动态内存申请+模块化设计
1.创建链表（创建一个表头表示整个链表）
2.创建结点
3.插入结点
4.删除节点 
5.打印遍历链表（测试） 
*/
struct student
{
	char name[20];
	int num;
	int math;
}; 
struct Node
{
	struct student data;             //数据域 
	struct Node* next;   //指针域 
};
/******************************************创建链表***************************************/ 
 struct Node* createList()
{
  struct Node* headNode = (struct Node*)malloc(sizeof(struct Node));
    //headNode从指针变成结构体变量 
    //变量使用前必须被初始化
    //headNode->data = 1;   //数据域一般不初始化 
  headNode->next = NULL;
  return headNode; 
}
/*****************************************创建结点****************************************/
struct Node* createNode(struct student data)
{
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data = data;
	newNode->next = NULL;
	return newNode;
} 
/*****************************************打印链表****************************************/
void printList(struct Node* headNode) 
{
 struct Node* pMove = headNode->next;   //定义一个会移动的指针从第二个节点打印
 printf("name\tnum\tmath\t");
 while(pMove)          //当这个节点不为空时打印
 {
 	printf("%s\t%d\t%d\n",pMove->data.name,pMove->data.num,pMove->data.math);
 	pMove = pMove->next;    //指针移向下一位 
 } 
  printf("\n"); 
}
/*****************************************插入结点(表头法插入)****************************************/ 
void  insertNodeByHead(struct Node* headNode,struct student data) //插入哪个链表表头，插入什么数据 
{
	//1.创建插入的结点
	struct Node* newNode = createNode(data);
	newNode->next = headNode->next;
	headNode->next = newNode;
}
/*****************************************删除结点(指定位置(编号)删除)****************************************/ 
void deleteNodeByAppoinNum(struct Node* headNode,int num)  //指定位置，指定数据 
{
	struct Node* posNode = headNode->next;
	struct Node* posNodeFront = headNode;
	if(posNode == NULL) //链表是空的
	  printf("无法删除，链表为空\n");
	else 
	{
		while(posNode->data.num != num)  //循环，如果找不到就继续找
		{
		  	posNodeFront=posNode;
		  	posNode=posNodeFront->next;
		  	if(posNode == NULL )
		  	{
		  		printf("没有找到相关信息，无法删除\n");
		  		return ; //结束循环 
			}
		} 
		posNodeFront->next = posNode->next;
		free(posNode); 
	 } 
} 





 
int main()
{ 
  struct Node* list = createList();  // 创建一个名为list的链表 
  struct student info;  //创建一个名为info学生结构体
  while(1)
  {
  	printf("请输入学生的姓名:\n");
	scanf("%s",info.name); 
	printf("请输入学生的学号:\n");
	scanf("%d",&info.num);
	printf("请输入学生的数学成绩:\n");
	scanf("%d",&info.math);
	insertNodeByHead(list,info);   //插入链表 
	printf("continue(Y/N)?\n");
	setbuf(stdin,NULL);    //清除缓冲区
	int choice=getchar();
	if(choice == 'N'||choice == 'n' )
	{
		break;
	}
   } 
   printList(list);
   printf("请输入要删除的学生编号：");
   scanf("%d",&info.num);
   deleteNodeByAppoinNum(list,info.num);
   printList(list);
   system("pause");
  return 0;	
} 
